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
typedef  int /*<<< orphan*/  __u32 ;

/* Variables and functions */
 int /*<<< orphan*/  dprintk (char*) ; 

__attribute__((used)) static int lgdt3304_read_ber(struct dvb_frontend *fe, __u32 *ber)
{
	dprintk("read ber\n");
	return 0;
}