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


/* defines MAX_HTML_CHAR_LEN as 15 */
#include "html_util.h"


short c7e3_numUtf8Bytes(char utf8Byte) {
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

int c7e3_utf8ToHtml(char* utf8, char* html) {
  return 0;
}
