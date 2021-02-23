#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {char** dt_cpp_argv; char* dt_cpp_path; int /*<<< orphan*/ * dt_pcb; } ;
typedef  TYPE_1__ dtrace_hdl_t ;

/* Variables and functions */
 int /*<<< orphan*/  EDT_BADOPTCTX ; 
 int /*<<< orphan*/  EDT_BADOPTVAL ; 
 int /*<<< orphan*/  EDT_NOMEM ; 
 int dt_set_errno (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ strbasename (char*) ; 
 char* strdup (char const*) ; 

__attribute__((used)) static int
dt_opt_cpp_path(dtrace_hdl_t *dtp, const char *arg, uintptr_t option)
{
	char *cpp;

	if (arg == NULL)
		return (dt_set_errno(dtp, EDT_BADOPTVAL));

	if (dtp->dt_pcb != NULL)
		return (dt_set_errno(dtp, EDT_BADOPTCTX));

	if ((cpp = strdup(arg)) == NULL)
		return (dt_set_errno(dtp, EDT_NOMEM));

	dtp->dt_cpp_argv[0] = (char *)strbasename(cpp);
	free(dtp->dt_cpp_path);
	dtp->dt_cpp_path = cpp;

	return (0);
}