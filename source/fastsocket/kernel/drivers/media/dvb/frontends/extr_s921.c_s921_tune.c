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
struct dvb_frontend_parameters {int dummy; } ;
struct dvb_frontend {int dummy; } ;
typedef  int /*<<< orphan*/  fe_status_t ;

/* Variables and functions */
 unsigned int FE_TUNE_MODE_ONESHOT ; 
 int /*<<< orphan*/  dprintk (char*) ; 
 int /*<<< orphan*/  s921_read_status (struct dvb_frontend*,int /*<<< orphan*/ *) ; 
 int s921_set_frontend (struct dvb_frontend*,struct dvb_frontend_parameters*) ; 

__attribute__((used)) static int s921_tune(struct dvb_frontend *fe,
			struct dvb_frontend_parameters *params,
			unsigned int mode_flags,
			unsigned int *delay,
			fe_status_t *status)
{
	int rc = 0;

	dprintk("\n");

	if (params != NULL)
		rc = s921_set_frontend(fe, params);

	if (!(mode_flags & FE_TUNE_MODE_ONESHOT))
		s921_read_status(fe, status);

	return rc;
}