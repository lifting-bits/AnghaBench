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
struct channel {TYPE_1__* board; } ;
struct TYPE_2__ {int /*<<< orphan*/  port; } ;

/* Variables and functions */
 int FEPMEM ; 
 int /*<<< orphan*/  epcaassert (int,char*) ; 
 int inb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pcxi_assertmemoff(struct channel *ch)
{
	epcaassert(!(inb(ch->board->port) & FEPMEM), "Memory on");
}