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
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  vR; } ;

/* Variables and functions */
 int /*<<< orphan*/  PDU_GET_NEXT_Vr (int /*<<< orphan*/ ) ; 
 TYPE_1__* llc_sk (struct sock*) ; 

int llc_conn_ac_inc_vr_by_1(struct sock *sk, struct sk_buff *skb)
{
	llc_sk(sk)->vR = PDU_GET_NEXT_Vr(llc_sk(sk)->vR);
	return 0;
}