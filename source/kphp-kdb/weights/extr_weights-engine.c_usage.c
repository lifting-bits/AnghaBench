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
 char* FullVersionStr ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  parse_usage () ; 
 int /*<<< orphan*/  printf (char*,char*,char*) ; 
 char* progname ; 

void usage (void) {
  printf ("usage: %s [-v] [-r] [-i] [-p<port>] [-u<username>] [-b<backlog>] [-c<max-conn>] [-a<binlog-name>] [-l<log-name>] <binlog>\n"
	  "\t%s\n"
	  "\tPerforms weights queries.\n"
	  , progname,
	  FullVersionStr);
  parse_usage ();
  exit(2);
}