/* asserts.c */

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

#include<stdio.h>
#include<stdlib.h>
#include"asserts.h"

/* Global container for errors. */
c7e3_Message* c7e3_errors = NULL;

void c7e3_assert(int statement, char* message)
{
  if (!statement)
  {
    c7e3_Message* newError = malloc(sizeof(c7e3_Message));
    newError->errorMessage = message;
    newError->next = c7e3_errors;
    c7e3_errors = newError;
  }
}

void c7e3_report()
{
  c7e3_Message* head = c7e3_errors;
  if (head == NULL)
  {
    printf("All test passed.\n\n");
  }
  while(head != NULL)
  {
    printf("Error: %s\n\n", head->errorMessage);
    head = head->next;
  }
}
