#include "socket.h"

#define SOCKET_STATE_NONE 0
#define SOCKET_STATE_ACKED 1
#define SOCKET_STATE_READ 2
#define SOCKET_STATE_BLOCKED_NEWDATA 3
#define SOCKET_STATE_BLOCKED_CLOSE 4
#define SOCKET_STATE_BLOCKED_SEND 5
#define SOCKET_STATE_DATA_SENT 6

/*---------------------------------------------------------------------------*/
static char
send_data(struct socket *s)
{
  if(s->state != SOCKET_STATE_DATA_SENT || uip_rexmit()) {
    if(s->sendlen > uip_mss()) {
      uip_send(s->sendptr, uip_mss());
    } else {
      uip_send(s->sendptr, s->sendlen);
    }
    s->state = SOCKET_STATE_DATA_SENT;
    return 1;
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
static char
data_sent(struct socket *s)
{
  if(s->state == SOCKET_STATE_DATA_SENT && uip_acked()) {
    if(s->sendlen > uip_mss()) {
      s->sendlen -= uip_mss();
      s->sendptr += uip_mss();
    } else {
      s->sendptr += s->sendlen;
      s->sendlen = 0;
    }
    s->state = SOCKET_STATE_ACKED;
    return 1;
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
PT_THREAD(socket_send(struct socket *s, char *buf, unsigned int len))
{
  PT_START(&s->socketpt);

  if(len == 0) {
    PT_EXIT(&s->socketpt);
  }
  
  s->sendptr = buf;
  s->sendlen = len;
  
  while(s->sendlen > 0) {
    PT_WAIT_UNTIL(&s->socketpt, data_sent(s) && send_data(s));
  }

  PT_EXIT(&s->socketpt);
}
/*---------------------------------------------------------------------------*/
/*PT_THREAD(socket_closew(struct socket *socket))
{
  PT_START(&socket->socketpt);
  uip_close();
  socket->state = SOCKET_STATE_BLOCKED_CLOSE;  
  PT_WAIT_UNTIL(&socket->socketpt,
		uip_closed() || uip_timedout() || uip_aborted());
  PT_EXIT(&socket->socketpt);
}*/
/*---------------------------------------------------------------------------*/
static char
newdata_available(struct socket *s)
{
  if(s->state == SOCKET_STATE_READ) {
    /* Data in uip_appdata buffer already consumed. */
    s->state = SOCKET_STATE_BLOCKED_NEWDATA;
    return 0;
  } else if(uip_newdata()) {
    /* There is new data that has not been consumed. */
    return 1;
  } else {
    /* There is no new data. */
    return 0;
  }
}
/*---------------------------------------------------------------------------*/
PT_THREAD(socket_readto(struct socket *socket, unsigned char c))
{

  PT_START(&socket->socketpt);

  uipbuf_setup(&socket->buf, socket->bufptr, socket->bufsize);
  
  /* XXX: Should add uipbuf_checkmarker() before do{} loop, if
     incoming data has been handled while waiting for a write. */

  do {
    if(socket->readlen == 0) {
      PT_WAIT_UNTIL(&socket->socketpt, newdata_available(socket));  
      socket->state = SOCKET_STATE_READ;
      socket->readptr = (u8_t *)uip_appdata;
      socket->readlen = uip_datalen();
    }
  } while((uipbuf_bufto(&socket->buf, c,
			&socket->readptr,
			&socket->readlen) & UIPBUF_FOUND) == 0 &&
	  socket->readlen > 0);

  if(uipbuf_len(&socket->buf) == 0) {
    socket->state = SOCKET_STATE_NONE;
    PT_RESTART(&socket->socketpt);
  }
  
  PT_EXIT(&socket->socketpt);
}
/*---------------------------------------------------------------------------*/
void
socket_init(struct socket *socket, char *buffer, unsigned int buffersize)
{
  socket->state = SOCKET_STATE_NONE;
  socket->readlen = 0;
  socket->bufptr = buffer;
  socket->bufsize = buffersize;
  uipbuf_setup(&socket->buf, buffer, buffersize);
  PT_INIT(&socket->pt);
  PT_INIT(&socket->socketpt);
}
/*---------------------------------------------------------------------------*/