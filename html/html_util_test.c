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


#include "html_util.h"
#include "asserts.h"

int main(int argc, char* argv[])
{
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
  c7e3_report();
  return 0;
}
