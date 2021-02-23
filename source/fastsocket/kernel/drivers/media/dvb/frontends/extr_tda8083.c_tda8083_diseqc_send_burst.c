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
struct tda8083_state {int dummy; } ;
struct dvb_frontend {struct tda8083_state* demodulator_priv; } ;
typedef  int /*<<< orphan*/  fe_sec_mini_cmd_t ;

/* Variables and functions */
 int /*<<< orphan*/  tda8083_send_diseqc_burst (struct tda8083_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tda8083_writereg (struct tda8083_state*,int,int) ; 

__attribute__((used)) static int tda8083_diseqc_send_burst(struct dvb_frontend* fe, fe_sec_mini_cmd_t burst)
{
	struct tda8083_state* state = fe->demodulator_priv;

	tda8083_send_diseqc_burst (state, burst);
	tda8083_writereg (state, 0x00, 0x3c);
	tda8083_writereg (state, 0x00, 0x04);

	return 0;
}