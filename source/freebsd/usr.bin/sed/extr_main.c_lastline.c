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
 int EOF ; 
 scalar_t__ feof (int /*<<< orphan*/ ) ; 
 int getc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  infile ; 
 int /*<<< orphan*/ * inplace ; 
 scalar_t__ ispan ; 
 scalar_t__ next_files_have_lines () ; 
 int /*<<< orphan*/  ungetc (int,int /*<<< orphan*/ ) ; 

int
lastline(void)
{
	int ch;

	if (feof(infile)) {
		return !(
		    (inplace == NULL || ispan) &&
		    next_files_have_lines());
	}
	if ((ch = getc(infile)) == EOF) {
		return !(
		    (inplace == NULL || ispan) &&
		    next_files_have_lines());
	}
	ungetc(ch, infile);
	return (0);
}