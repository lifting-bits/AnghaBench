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
 int YY_ONE_LINE_COMMENT ; 
 int get_skip_sym () ; 
 int /*<<< orphan*/  yy_error_sym (char*,int) ; 

__attribute__((used)) static int skip_ONE_LINE_COMMENT(int sym) {
	if (sym != YY_ONE_LINE_COMMENT) {
		yy_error_sym("<ONE_LINE_COMMENT> expected, got", sym);
	}
	sym = get_skip_sym();
	return sym;
}