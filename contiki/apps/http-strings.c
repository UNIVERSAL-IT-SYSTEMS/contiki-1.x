char http_http[8] = 
/* "http://" */
{0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, };
char http_200[5] = 
/* "200 " */
{0x32, 0x30, 0x30, 0x20, };
char http_301[5] = 
/* "301 " */
{0x33, 0x30, 0x31, 0x20, };
char http_302[5] = 
/* "302 " */
{0x33, 0x30, 0x32, 0x20, };
char http_get[5] = 
/* "GET " */
{0x47, 0x45, 0x54, 0x20, };
char http_10[9] = 
/* "HTTP/1.0" */
{0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x30, };
char http_11[9] = 
/* "HTTP/1.1" */
{0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x31, };
char http_content_type[15] = 
/* "Content-Type: " */
{0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a, 0x20, };
char http_texthtml[10] = 
/* "text/html" */
{0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d, 0x6c, };
char http_location[11] = 
/* "Location: " */
{0x4c, 0x6f, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20, };
char http_host[7] = 
/* "Host: " */
{0x48, 0x6f, 0x73, 0x74, 0x3a, 0x20, };
char http_fields[] = 
#ifdef __ATARI__
/* "Connection: close\r\nUser-Agent: Contiki/1.0 (Atari 800; http://dunkels.com/adam/contiki/)\r\n\r\n" */
{0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20, 0x63, 0x6c, 0x6f, 0x73, 0x65,0x0d, 0x0a, 0x55, 0x73, 0x65, 0x72, 0x2d, 0x41, 0x67, 0x65, 0x6e, 0x74, 0x3a, 0x20, 0x43, 0x6f, 0x6e,0x74, 0x69, 0x6b, 0x69, 0x2f, 0x31, 0x2e, 0x30, 0x20, 0x28, 0x41, 0x74, 0x61, 0x72, 0x69, 0x20, 0x38, 0x30, 0x30, 0x3b, 0x20, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x64, 0x75, 0x6e, 0x6b, 0x65, 0x6c, 0x73, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x61, 0x64, 0x61, 0x6d, 0x2f, 0x63, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2f, 0x29, 0x0d, 0x0a, 0x0d, 0x0a};
#else  /* above Atari, below not */
/* "Connection: close\r\nUser-Agent: Contiki/1.0 (Commodore 64; http://dunkels.com/adam/contiki/)\r\n\r\n" */
{0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20, 0x63, 0x6c, 0x6f, 0x73, 0x65, 0xd, 0xa, 0x55, 0x73, 0x65, 0x72, 0x2d, 0x41, 0x67, 0x65, 0x6e, 0x74, 0x3a, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2f, 0x31, 0x2e, 0x30, 0x20, 0x28, 0x43, 0x6f, 0x6d, 0x6d, 0x6f, 0x64, 0x6f, 0x72, 0x65, 0x20, 0x36, 0x34, 0x3b, 0x20, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x64, 0x75, 0x6e, 0x6b, 0x65, 0x6c, 0x73, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x61, 0x64, 0x61, 0x6d, 0x2f, 0x63, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2f, 0x29, 0xd, 0xa, 0xd, 0xa, };
#endif /* not Atari */
char http_crnl[3] = 
/* "\r\n" */
{0xd, 0xa, };
char http_webserver_d64_headers[105] = 
/* "HTTP/1.0 200 OK\r\nServer: Contiki/1.0\r\nContent-Type: application/octet-stream\r\nContent-Length: 174848\r\n\r\n" */
{0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x30, 0x20, 0x32, 0x30, 0x30, 0x20, 0x4f, 0x4b, 0xd, 0xa, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x3a, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2f, 0x31, 0x2e, 0x30, 0xd, 0xa, 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x2f, 0x6f, 0x63, 0x74, 0x65, 0x74, 0x2d, 0x73, 0x74, 0x72, 0x65, 0x61, 0x6d, 0xd, 0xa, 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x4c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x3a, 0x20, 0x31, 0x37, 0x34, 0x38, 0x34, 0x38, 0xd, 0xa, 0xd, 0xa, };
