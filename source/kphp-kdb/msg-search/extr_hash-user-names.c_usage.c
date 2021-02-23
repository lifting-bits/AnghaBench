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
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 char* progname ; 

void usage (void) {
  printf ("usage: %s [-v] <members-fname-1> [<members-fname-2> ...]\n"
	  "\tResulting hash list file is written to stdout\n"
	  "\t-v\toutput statistical information into stderr\n",
	  progname);
  exit(2);
}