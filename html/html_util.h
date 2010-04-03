/* html_util.h */

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

/* Some unicode characters are represented in the form &#21494; so a buffer
   which should hold the HTML character should be able to hold as mush as
   MAX_HTML_CHAR_LEN bytes. */
#define MAX_HTML_CHAR_LEN 15

short c7e3_numUtf8Bytes(char utf8Byte);
int c7e3_utf8ToHtml(char* utf8, char* html); 
