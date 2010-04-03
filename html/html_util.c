/* html_util.c */

/* Copyright 2010 Jeffrey William Scudder

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#include <string.h>
#include <stdio.h>
#include <stdint.h>
/* defines C7E3_MAX_HTML_CHAR_LEN as 15 */
#include "html_util.h"


short c7e3_numUtf8Bytes(char utf8Byte)
{
  /* The pattern for the first byte in a UTf8 character:
     0xxx xxxx = 1 byte
     110x xxxx = 2 bytes
     1110 xxxx = 3 bytes
     1111 0xxx = 4 bytes
     (see http://en.wikipedia.org/wiki/UTF-8 ) */
  /* Look at just the most significant digit. */
  if ((utf8Byte & 0x80) == 0) {
    return 1;
  } else if ((utf8Byte & 0xE0) == 0xC0) {
    return 2;
  } else if ((utf8Byte & 0xF0) == 0xE0) {
    return 3;
  } else if ((utf8Byte & 0xF8) == 0xF0) {
    return 4;
  }
  return 0;
}

short c7e3_utf8ToHtml(char* utf8, char* html)
{
  short charLen = c7e3_numUtf8Bytes(utf8[0]);
  short charactersEmitted = 0;
  /* The unicode representation of the UTF8 character. */
  uint32_t codePoint = 0;

  if (charLen == 1) {
    /* This is an ascii character. */
    switch (utf8[0]) {
      case '<':
        strcpy(html, "&lt;");
        charactersEmitted = 4;
        break;
      case '>':
        strcpy(html, "&gt;");
        charactersEmitted = 4;
        break;
      case '"':
        strcpy(html, "&quot;");
        charactersEmitted = 6;
        break;
      default:
        html[0] = utf8[0];
        charactersEmitted = 1;
    }
  } else if (charLen != 0) {
    /* Convert 2-4 byte long UTF8 charcters. */
    switch (charLen) {
      case 2:
        /* 110yyyxx 10xxxxxx */
        codePoint = (0x3F & utf8[1]) | ((0x1F & utf8[0]) << 6);
        break;
      case 3:
        /* 1110yyyy 10yyyyxx 10xxxxxx */
        codePoint = (0x3F & utf8[2]) | ((0x3F & utf8[1]) << 6) |
                    ((0x0F & utf8[0]) << 12);
        break;
      case 4:
        /* 11110zzz 10zzyyyy 10yyyyxx 10xxxxxx */
        codePoint = (0x3F & utf8[3]) | ((0x3F & utf8[2]) << 6) |
                    ((0x3F & utf8[1]) << 12) | ((0x07 & utf8[0]) << 18);
        break;
    }
    sprintf(html, "&#%d;", codePoint);
    charactersEmitted = strlen(html);
  }
  
  /* Terminate the HTML string. */
  html[charactersEmitted] = '\0';
  return charactersEmitted;
}
