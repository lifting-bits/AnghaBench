#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ error; } ;

/* Variables and functions */
 int do_rpc_fetch_string (char**) ; 
 char* emalloc (int) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 scalar_t__ strdup (char*) ; 
 TYPE_1__ tl ; 

int tl_eparse_string (char **s) {
  if (tl.error) { return -1; }
  int len = do_rpc_fetch_string (s);
  if (len < 0) {
    tl.error = strdup (*s);
    *s = 0;
    return -1;
  }
  char *t = emalloc (len + 1);
  memcpy (t, *s, len);
  t[len] = 0;
  *s = t;
  return len;
}