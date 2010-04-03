/* html_util_test.c */

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
#include "html_util.h"
#include "asserts.h"

int main(int argc, char* argv[])
{
  char html[C7E3_MAX_HTML_CHAR_LEN];
  short htmlLength;

  c7e3_assert(c7e3_numUtf8Bytes('A') == 1, 
      "A should take 1 unicode char");
  c7e3_assert(c7e3_numUtf8Bytes(0xA0) == 0, 
      "UTF8 characters can't start with 10xx xxxx");
  c7e3_assert(c7e3_numUtf8Bytes(0) == 1, 
      "0 should be just 1 char");
  c7e3_assert(c7e3_numUtf8Bytes(0xFF) == 0, 
      "UTF8 characters can't start with 1111 1xxx");
  c7e3_assert(c7e3_numUtf8Bytes(0xDF) == 2, 
      "An initial 110x xxxx should indicate 2 bytes");
  c7e3_assert(c7e3_numUtf8Bytes(0xC0) == 2, 
      "Initial 110x xxxx should indicate 2 bytes");
  c7e3_assert(c7e3_numUtf8Bytes(0xEF) == 3, 
      "An initial 1110 xxxx should indicate 3 bytes");
  c7e3_assert(c7e3_numUtf8Bytes(0xF0) == 4, 
      "An initial 1111 0xxx should indicate 4 bytes");

  
  htmlLength = c7e3_utf8ToHtml("a", html);
  c7e3_assert(strcmp(html, "a") == 0,
      "A plain ascii character should not be converted.");
  c7e3_assert(htmlLength == 1,
      "A plain ascii character should take one character.");
  htmlLength = c7e3_utf8ToHtml("<", html);
  c7e3_assert(strcmp(html, "&lt;") == 0,
      "A < should be converted to &lt;.");
  c7e3_assert(htmlLength == 4,
      "A converted < should be 4 characters long.");
  htmlLength = c7e3_utf8ToHtml(">", html);
  c7e3_assert(strcmp(html, "&gt;") == 0,
      "A > should be converted to &lt;.");
  c7e3_assert(htmlLength == 4,
      "A converted > should be 4 characters long.");
  htmlLength = c7e3_utf8ToHtml("\"", html);
  c7e3_assert(strcmp(html, "&quot;") == 0,
      "A \" should be converted to &lt;.");
  c7e3_assert(htmlLength == 6,
      "A converted \" should be 6 characters long.");

  /* The character alpha is Unicode 0x0391 which we convert to &#945;.
     In UTF8, it is 0xCE 0xB1 */
  htmlLength = c7e3_utf8ToHtml("\xCE\xB1", html);
  c7e3_assert(strcmp(html, "&#945;") == 0,
      "The alpha character should be converted to &#945;.");
  c7e3_assert(htmlLength == 6,
      "A converted alpha character should be 6 characters long.");

  /* Unicode Character 'FISHEYE' (U+25C9) */
  htmlLength = c7e3_utf8ToHtml("\xE2\x97\x89", html);
  c7e3_assert(strcmp(html, "&#9673;") == 0,
      "The fisheye character should be converted to &#9673;.");
  c7e3_assert(htmlLength == 7,
      "A converted fisheye character should be 7 characters long.");
  
  htmlLength = c7e3_utf8ToHtml("\xF0\xAF\x8D\x81", html);
  c7e3_assert(strcmp(html, "&#193345;") == 0,
      "The 4 UTF8 byte character should be converted to &#193345;.");
  c7e3_assert(htmlLength == 9,
      "The converted 4 UTF8 byte character should be 9 characters long.");
  
  c7e3_report();
  return 0;
}
