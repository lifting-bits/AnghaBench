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
typedef  int /*<<< orphan*/  atf_tc_t ;

/* Variables and functions */
 int /*<<< orphan*/  overwritebody (int /*<<< orphan*/  const*,int,int) ; 

__attribute__((used)) static void
overwrite_trunc(const atf_tc_t *tc, const char *mp)
{

	overwritebody(tc, 1<<16, true);
}