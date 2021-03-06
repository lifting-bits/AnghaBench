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
typedef  int /*<<< orphan*/  wchar_t ;

/* Variables and functions */
 int _tomb (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  warn (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * widemsg ; 

int
to_mb(char *mb, wchar_t wc)
{
	int	rv;

	if ((rv = _tomb(mb, wc)) < 0) {
		warn("%s", widemsg);
		free(widemsg);
		widemsg = NULL;
	}
	return (rv);
}