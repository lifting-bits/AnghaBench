#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct lgdt3305_state {int snr; } ;
struct TYPE_2__ {int (* read_snr ) (struct dvb_frontend*,int*) ;} ;
struct dvb_frontend {TYPE_1__ ops; struct lgdt3305_state* demodulator_priv; } ;

/* Variables and functions */
 scalar_t__ lg_fail (int) ; 
 int stub1 (struct dvb_frontend*,int*) ; 

__attribute__((used)) static int lgdt3305_read_signal_strength(struct dvb_frontend *fe,
					 u16 *strength)
{
	/* borrowed from lgdt330x.c
	 *
	 * Calculate strength from SNR up to 35dB
	 * Even though the SNR can go higher than 35dB,
	 * there is some comfort factor in having a range of
	 * strong signals that can show at 100%
	 */
	struct lgdt3305_state *state = fe->demodulator_priv;
	u16 snr;
	int ret;

	*strength = 0;

	ret = fe->ops.read_snr(fe, &snr);
	if (lg_fail(ret))
		goto fail;
	/* Rather than use the 8.8 value snr, use state->snr which is 8.24 */
	/* scale the range 0 - 35*2^24 into 0 - 65535 */
	if (state->snr >= 8960 * 0x10000)
		*strength = 0xffff;
	else
		*strength = state->snr / 8960;
fail:
	return ret;
}