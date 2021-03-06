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
 scalar_t__ ISSPACE (char const) ; 
 scalar_t__ strlen (char const*) ; 

__attribute__((used)) static int clipLength(const char *z){
  int n = (int)strlen(z);
  while( n>0 && ISSPACE(z[n-1]) ){ n--; }
  return n;
}