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
typedef  int /*<<< orphan*/  u_int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  process_do_stat (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
process_lstat(u_int32_t id)
{
	process_do_stat(id, 1);
}