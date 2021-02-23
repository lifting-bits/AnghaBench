#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  dt_lib_path; } ;
typedef  TYPE_1__ dtrace_hdl_t ;
struct TYPE_9__ {int /*<<< orphan*/ * dir_path; } ;
typedef  TYPE_2__ dt_dirpath_t ;

/* Variables and functions */
 int /*<<< orphan*/  EDT_BADOPTVAL ; 
 int /*<<< orphan*/  EDT_NOMEM ; 
 int /*<<< orphan*/  dt_list_append (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int dt_set_errno (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 TYPE_2__* malloc (int) ; 
 int /*<<< orphan*/ * strdup (char const*) ; 

__attribute__((used)) static int
dt_opt_libdir(dtrace_hdl_t *dtp, const char *arg, uintptr_t option)
{
	dt_dirpath_t *dp;

	if (arg == NULL)
		return (dt_set_errno(dtp, EDT_BADOPTVAL));

	if ((dp = malloc(sizeof (dt_dirpath_t))) == NULL ||
	    (dp->dir_path = strdup(arg)) == NULL) {
		free(dp);
		return (dt_set_errno(dtp, EDT_NOMEM));
	}

	dt_list_append(&dtp->dt_lib_path, dp);
	return (0);
}