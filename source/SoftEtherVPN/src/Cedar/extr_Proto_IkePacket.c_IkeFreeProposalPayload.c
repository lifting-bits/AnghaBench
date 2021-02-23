#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * PayloadList; int /*<<< orphan*/ * Spi; } ;
typedef  TYPE_1__ IKE_PACKET_PROPOSAL_PAYLOAD ;

/* Variables and functions */
 int /*<<< orphan*/  FreeBuf (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IkeFreePayloadList (int /*<<< orphan*/ *) ; 

void IkeFreeProposalPayload(IKE_PACKET_PROPOSAL_PAYLOAD *t)
{
	// Validate arguments
	if (t == NULL)
	{
		return;
	}

	if (t->Spi != NULL)
	{
		FreeBuf(t->Spi);
		t->Spi = NULL;
	}

	if (t->PayloadList != NULL)
	{
		IkeFreePayloadList(t->PayloadList);
		t->PayloadList = NULL;
	}
}