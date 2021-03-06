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
 int strcmp (char const*,char const*) ; 

__attribute__((used)) static int safe_strcmp(const char *a, const char *b){
  if( a==b ) return 0;
  if( a==0 ) return -1;
  if( b==0 ) return 1;
  return strcmp(a,b);
}