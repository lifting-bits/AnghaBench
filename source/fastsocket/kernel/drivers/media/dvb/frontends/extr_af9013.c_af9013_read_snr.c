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
typedef  int /*<<< orphan*/  u16 ;
struct dvb_frontend {struct af9013_state* demodulator_priv; } ;
struct af9013_state {int /*<<< orphan*/  snr; } ;

/* Variables and functions */
 int af9013_update_statistics (struct dvb_frontend*) ; 

__attribute__((used)) static int af9013_read_snr(struct dvb_frontend *fe, u16 *snr)
{
	struct af9013_state *state = fe->demodulator_priv;
	int ret;
	ret = af9013_update_statistics(fe);
	*snr = state->snr;
	return ret;
}