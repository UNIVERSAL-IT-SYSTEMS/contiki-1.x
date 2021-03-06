/*
 * Copyright (c) 2004, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 * 3. Neither the name of the Institute nor the names of its contributors 
 *    may be used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE. 
 *
 * This file is part of the Contiki operating system.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 * $Id: html-strings.c,v 1.3 2004/09/12 20:24:54 adamdunkels Exp $
 */
const char html_slasha[4] = 
/* "/a\0" */
{0x2f, 0x61, 00, };
const char html_slashcenter[9] = 
/* "/center\0" */
{0x2f, 0x63, 0x65, 0x6e, 0x74, 0x65, 0x72, 00, };
const char html_slashform[7] = 
/* "/form\0" */
{0x2f, 0x66, 0x6f, 0x72, 0x6d, 00, };
const char html_slashh[4] = 
/* "/h\0" */
{0x2f, 0x68, 00, };
const char html_slashscript[9] = 
/* "/script\0" */
{0x2f, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 00, };
const char html_slashselect[9] = 
/* "/select\0" */
{0x2f, 0x73, 0x65, 0x6c, 0x65, 0x63, 0x74, 00, };
const char html_slashstyle[8] = 
/* "/style\0" */
{0x2f, 0x73, 0x74, 0x79, 0x6c, 0x65, 00, };
const char html_a[3] = 
/* "a\0" */
{0x61, 00, };
const char html_body[6] = 
/* "body\0" */
{0x62, 0x6f, 0x64, 0x79, 00, };
const char html_br[4] = 
/* "br\0" */
{0x62, 0x72, 00, };
const char html_center[8] = 
/* "center\0" */
{0x63, 0x65, 0x6e, 0x74, 0x65, 0x72, 00, };
const char html_form[6] = 
/* "form\0" */
{0x66, 0x6f, 0x72, 0x6d, 00, };
const char html_frame[7] = 
/* "frame\0" */
{0x66, 0x72, 0x61, 0x6d, 0x65, 00, };
const char html_h1[4] = 
/* "h1\0" */
{0x68, 0x31, 00, };
const char html_h2[4] = 
/* "h2\0" */
{0x68, 0x32, 00, };
const char html_h3[4] = 
/* "h3\0" */
{0x68, 0x33, 00, };
const char html_h4[4] = 
/* "h4\0" */
{0x68, 0x34, 00, };
const char html_img[5] = 
/* "img\0" */
{0x69, 0x6d, 0x67, 00, };
const char html_input[7] = 
/* "input\0" */
{0x69, 0x6e, 0x70, 0x75, 0x74, 00, };
const char html_li[4] = 
/* "li\0" */
{0x6c, 0x69, 00, };
const char html_p[3] = 
/* "p\0" */
{0x70, 00, };
const char html_script[8] = 
/* "script\0" */
{0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 00, };
const char html_select[8] = 
/* "select\0" */
{0x73, 0x65, 0x6c, 0x65, 0x63, 0x74, 00, };
const char html_style[7] = 
/* "style\0" */
{0x73, 0x74, 0x79, 0x6c, 0x65, 00, };
const char html_tr[4] = 
/* "tr\0" */
{0x74, 0x72, 00, };
const char html_href[6] = 
/* "href\0" */
{0x68, 0x72, 0x65, 0x66, 00, };
const char html_alt[5] = 
/* "alt\0" */
{0x61, 0x6c, 0x74, 00, };
const char html_src[5] = 
/* "src\0" */
{0x73, 0x72, 0x63, 00, };
const char html_type[6] = 
/* "type\0" */
{0x74, 0x79, 0x70, 0x65, 00, };
const char html_submit[8] = 
/* "submit\0" */
{0x73, 0x75, 0x62, 0x6d, 0x69, 0x74, 00, };
const char html_value[7] = 
/* "value\0" */
{0x76, 0x61, 0x6c, 0x75, 0x65, 00, };
const char html_action[8] = 
/* "action\0" */
{0x61, 0x63, 0x74, 0x69, 0x6f, 0x6e, 00, };
const char html_name[6] = 
/* "name\0" */
{0x6e, 0x61, 0x6d, 0x65, 00, };
const char html_text[6] = 
/* "text\0" */
{0x74, 0x65, 0x78, 0x74, 00, };
const char html_size[6] = 
/* "size\0" */
{0x73, 0x69, 0x7a, 0x65, 00, };
const char html_image[7] = 
/* "image\0" */
{0x69, 0x6d, 0x61, 0x67, 0x65, 00, };
