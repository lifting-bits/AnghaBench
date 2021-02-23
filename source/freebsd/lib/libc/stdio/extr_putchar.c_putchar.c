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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  FLOCKFILE_CANCELSAFE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FUNLOCKFILE_CANCELSAFE () ; 
 int __sputc (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * stdout ; 

int
putchar(int c)
{
	int retval;
	FILE *so = stdout;

	FLOCKFILE_CANCELSAFE(so);
	/* Orientation set by __sputc() when buffer is full. */
	/* ORIENT(so, -1); */
	retval = __sputc(c, so);
	FUNLOCKFILE_CANCELSAFE();
	return (retval);
}