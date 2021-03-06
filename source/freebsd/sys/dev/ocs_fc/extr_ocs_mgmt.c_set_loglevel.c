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
typedef  int /*<<< orphan*/  ocs_t ;

/* Variables and functions */
 int /*<<< orphan*/  loglevel ; 
 int /*<<< orphan*/  ocs_strtoul (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
set_loglevel(ocs_t *ocs, char *name, char *value)
{

	loglevel = ocs_strtoul(value, NULL, 0);

	return 0;
}