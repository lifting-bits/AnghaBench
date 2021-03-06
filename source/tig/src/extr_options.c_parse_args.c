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
typedef  enum status_code { ____Placeholder_status_code } status_code ;

/* Variables and functions */
 int ERROR_OUT_OF_MEMORY ; 
 int SUCCESS ; 
 int /*<<< orphan*/  argv_copy (char const***,char const**) ; 

__attribute__((used)) static enum status_code
parse_args(const char ***args, const char *argv[])
{
	if (!argv_copy(args, argv))
		return ERROR_OUT_OF_MEMORY;
	return SUCCESS;
}