#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 char* memcpy (char*,char const*,size_t) ; 
 int strlen (char const*) ; 
 char* uv__malloc (size_t) ; 

char* uv__strdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* m = uv__malloc(len);
  if (m == NULL)
    return NULL;
  return memcpy(m, s, len);
}