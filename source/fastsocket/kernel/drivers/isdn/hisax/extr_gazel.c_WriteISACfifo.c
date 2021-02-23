#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
struct TYPE_3__ {int /*<<< orphan*/  ipac; int /*<<< orphan*/  isacfifo; } ;
struct TYPE_4__ {TYPE_1__ gazel; } ;
struct IsdnCardState {int subtyp; TYPE_2__ hw; } ;

/* Variables and functions */
#define  R647 131 
#define  R685 130 
#define  R742 129 
#define  R753 128 
 int /*<<< orphan*/  write_fifo (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  write_fifo_ipac (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void
WriteISACfifo(struct IsdnCardState *cs, u_char * data, int size)
{
	switch (cs->subtyp) {
		case R647:
		case R685:
			write_fifo(cs->hw.gazel.isacfifo, data, size);
			break;
		case R753:
		case R742:
			write_fifo_ipac(cs->hw.gazel.ipac, 0x80, data, size);
			break;
	}
}