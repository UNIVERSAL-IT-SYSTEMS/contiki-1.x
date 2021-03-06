/*
 * Copyright (c) 2002-2004, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution. 
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.  
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
 *
 * This file is part of the Contiki desktop environment
 *
 * $Id: plasma.c,v 1.1 2005/05/12 21:12:43 oliverschmidt Exp $
 *
 */

#include <stdlib.h>

#include "ctk.h"
#include "ctk-draw.h"
#include "ctk-mouse.h"
#include "ek.h"
#include "loader.h"

static unsigned char sinetab1[256] = {
  128, 131, 134, 137, 140, 143, 146, 149, 
  152, 156, 159, 162, 165, 168, 171, 174, 
  176, 179, 182, 185, 188, 191, 193, 196, 
  199, 201, 204, 206, 209, 211, 213, 216, 
  218, 220, 222, 224, 226, 228, 230, 232, 
  234, 236, 237, 239, 240, 242, 243, 245, 
  246, 247, 248, 249, 250, 251, 252, 252, 
  253, 254, 254, 255, 255, 255, 255, 255, 
  255, 255, 255, 255, 255, 255, 254, 254, 
  253, 252, 252, 251, 250, 249, 248, 247, 
  246, 245, 243, 242, 240, 239, 237, 236, 
  234, 232, 230, 228, 226, 224, 222, 220, 
  218, 216, 213, 211, 209, 206, 204, 201, 
  199, 196, 193, 191, 188, 185, 182, 179, 
  176, 174, 171, 168, 165, 162, 159, 156, 
  152, 149, 146, 143, 140, 137, 134, 131, 
  128, 124, 121, 118, 115, 112, 109, 106, 
  103,  99,  96,  93,  90,  87,  84,  81, 
   79,  76,  73,  70,  67,  64,  62,  59, 
   56,  54,  51,  49,  46,  44,  42,  39, 
   37,  35,  33,  31,  29,  27,  25,  23, 
   21,  19,  18,  16,  15,  13,  12,  10, 
    9,   8,   7,   6,   5,   4,   3,   3, 
    2,   1,   1,   0,   0,   0,   0,   0, 
    0,   0,   0,   0,   0,   0,   1,   1, 
    2,   3,   3,   4,   5,   6,   7,   8, 
    9,  10,  12,  13,  15,  16,  18,  19, 
   21,  23,  25,  27,  29,  31,  33,  35, 
   37,  39,  42,  44,  46,  49,  51,  54, 
   56,  59,  62,  64,  67,  70,  73,  76, 
   78,  81,  84,  87,  90,  93,  96,  99, 
  103, 106, 109, 112, 115, 118, 121, 124, 
};

static unsigned char sinetab2[256];
static unsigned char sinetab3[256];

static unsigned char colortab[256];

static unsigned char colors[16] =
  {
    0x00, 0x22, 0x55, 0x33,
    0xBB, 0xAA, 0xDD, 0xFF,
    0xDD, 0xAA, 0xBB, 0x99,
    0x11, 0x88, 0x00, 0x00
  };

#define XSIZE 25
#define YSIZE 24

#define XADD01 0xfe
#define YADD01 0x05

#define XADD1 0x04
#define YADD1 0x02
#define XADD2 0xfc
#define YADD2 0xf9

#define XADD 0x03
#define YADD 0xfe

#define MOVADD 0xfb

static unsigned char xplasma[XSIZE], yplasma[YSIZE];
static unsigned char xcnt, ycnt;
static unsigned char xcnt01, xcnt02, xcnt1, xcnt2;
static unsigned char ycnt01, ycnt02, ycnt1, ycnt2;

static unsigned char xadd02 = 0x01;
static unsigned char yadd02 = 0xfb;

static unsigned char movcnt;

/*static DISPATCHER_SIGHANDLER(sighandler, s, data);
static void idle(void);
static struct dispatcher_proc p =
  {DISPATCHER_PROC("Plasma screensaver", idle,
		   sighandler,
		   NULL)};
		   static ek_id_t id;*/
EK_EVENTHANDLER(eventhandler, ev, data);
EK_POLLHANDLER(pollhandler);
EK_PROCESS(p, "Plasma screensaver", EK_PRIO_LOWEST,
	   eventhandler, pollhandler, NULL);
static ek_id_t id = EK_ID_NONE;

/*-----------------------------------------------------------------------------------*/
static void
quit(void)
{
  *(char *)0xC051 = 0;

  ek_exit();
  id = EK_ID_NONE;
  LOADER_UNLOAD();
}
/*-----------------------------------------------------------------------------------*/
static void
scrninit(void)
{
  static int i;
  
  /* Make sine tables */
  for(i = 0; i < 256; ++i) {
    sinetab2[(unsigned char)i] = sinetab1[(unsigned char)i] / 2;
    sinetab3[(unsigned char)i] = sinetab1[(unsigned char)i] / 4;    
  }
    
  /* Make color table */
  for(i = 0; i < 256; ++i) {
    colortab[(unsigned char)i] = colors[(unsigned char)i / 16];
  }
    
  *(char *)0xC056 = 0;
  *(char *)0xC054 = 0;
  *(char *)0xC052 = 0;
  *(char *)0xC050 = 0;

  for(ycnt = 0; ycnt < 24; ++ycnt) {
    gotoy(ycnt);
    for(xcnt = 0; xcnt < 40; ++xcnt) {
      (*(unsigned char **)0x28)[xcnt] = 0x00;
    }
  }
}
/*-----------------------------------------------------------------------------------*/
EK_POLLHANDLER(pollhandler)
{
  static unsigned char i, x, y, xofs;
  
  if(ctk_mode_get() == CTK_MODE_SCREENSAVER) {

    xcnt1 = xcnt01;
    xcnt2 = xcnt02;
    
    for(i = 0; i < XSIZE; ++i) {
      xplasma[i] = sinetab1[xcnt1] + sinetab2[xcnt2];
      xcnt1 += XADD1;
      xcnt2 += XADD2;
    }

    ycnt1 = ycnt01;
    ycnt2 = ycnt02;
    
    for(i = 0; i < YSIZE; ++i) {
      yplasma[i] = sinetab1[ycnt1] + sinetab3[ycnt2];
      ycnt1 += YADD1;
      ycnt2 += YADD2;
    }

    xcnt01 += XADD01;
    xcnt02 += xadd02;
    ycnt01 += YADD01;
    ycnt02 += yadd02;

    
    yadd02 = sinetab3[ycnt] / 4;
    xadd02 = sinetab3[xcnt] / 4;

    ycnt += YADD;
    xcnt += XADD;

    movcnt += MOVADD;
    xofs = sinetab1[movcnt]/16;

    for(y = 0; y < YSIZE; ++y) {
      gotoy(y);
      for(x = 0; x < XSIZE; ++x) {
	(*(unsigned char **)0x28)[x + xofs] = colortab[(xplasma[x] + yplasma[y]) & 0xff];
      }
    }
  }
}
/*-----------------------------------------------------------------------------------*/
/*static
  DISPATCHER_SIGHANDLER(sighandler, s, data)*/
EK_EVENTHANDLER(eventhandler, ev, data)
{
  EK_EVENTHANDLER_ARGS(ev, data);

  if(ev == EK_EVENT_INIT) {
    ctk_mode_set(CTK_MODE_SCREENSAVER);
    ctk_mouse_hide();
   
    scrninit();

  } else if(ev == ctk_signal_screensaver_stop ||
	    ev == EK_EVENT_REQUEST_EXIT) {
    ctk_draw_init();
    ctk_desktop_redraw(NULL);
    /*    ctk_mode_set(CTK_MODE_NORMAL);*/
    quit();
  }
}
/*-----------------------------------------------------------------------------------*/
LOADER_INIT_FUNC(plasma_init, arg)
{
  arg_free(arg);
  
  if(id == EK_ID_NONE) {
    id = ek_start(&p);
  }
}
/*-----------------------------------------------------------------------------------*/
 
