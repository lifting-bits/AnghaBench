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
 int /*<<< orphan*/  _bcs_isspace (char const) ; 

const char *
_citrus_bcs_skip_nonws(const char *p)
{

	while (*p && !_bcs_isspace(*p))
		p++;

	return (p);
}