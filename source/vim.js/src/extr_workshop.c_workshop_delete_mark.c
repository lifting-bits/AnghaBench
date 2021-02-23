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
typedef  int /*<<< orphan*/  cbuf ;

/* Variables and functions */
 int BUFSIZ ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ WSDLEVEL (int) ; 
 int WS_TRACE ; 
 int WS_TRACE_VERBOSE ; 
 int /*<<< orphan*/  coloncmd (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vim_snprintf (char*,int,char*,int,char*) ; 
 int /*<<< orphan*/  wstrace (char*,char*,int) ; 

void
workshop_delete_mark(
	char		*filename,
	int		 markId)
{
    char	cbuf[BUFSIZ];	/* command buffer */

    /* Delete mark */
#ifdef WSDEBUG_TRACE
    if (WSDLEVEL(WS_TRACE_VERBOSE | WS_TRACE))
	wstrace("workshop_delete_mark(%s, %d (id))\n",
		filename, markId);
#endif

    vim_snprintf(cbuf, sizeof(cbuf),
				 "sign unplace %d file=%s", markId, filename);
    coloncmd(cbuf, TRUE);
}