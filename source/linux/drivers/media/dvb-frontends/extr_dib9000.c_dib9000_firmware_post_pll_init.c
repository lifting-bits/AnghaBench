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
struct dvb_frontend {struct dib9000_state* demodulator_priv; } ;
struct dib9000_state {int dummy; } ;

/* Variables and functions */
 int dib9000_fw_init (struct dib9000_state*) ; 

int dib9000_firmware_post_pll_init(struct dvb_frontend *fe)
{
	struct dib9000_state *state = fe->demodulator_priv;
	return dib9000_fw_init(state);
}