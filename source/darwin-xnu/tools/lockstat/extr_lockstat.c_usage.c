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
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 char* pgmname ; 
 int /*<<< orphan*/  stderr ; 

void 
usage()
{
	fprintf(stderr, "Usage: %s [all, spin, mutex, rw, <lock group name>] {<repeat interval>} {abs}\n", pgmname);
	exit(EXIT_FAILURE);
}