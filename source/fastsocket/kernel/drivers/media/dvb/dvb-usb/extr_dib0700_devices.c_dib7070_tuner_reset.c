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
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  deb_info (char*,int) ; 
 int dib7000p_set_gpio (struct dvb_frontend*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int dib7070_tuner_reset(struct dvb_frontend *fe, int onoff)
{
	deb_info("reset: %d", onoff);
	return dib7000p_set_gpio(fe, 8, 0, !onoff);
}