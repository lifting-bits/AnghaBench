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
struct bpf_sockopt {int* optval_end; int* optval; scalar_t__ level; scalar_t__ optname; int optlen; } ;
typedef  int __u8 ;

/* Variables and functions */
 scalar_t__ IP_TOS ; 
 scalar_t__ SOL_IP ; 

int _setsockopt(struct bpf_sockopt *ctx)
{
	__u8 *optval_end = ctx->optval_end;
	__u8 *optval = ctx->optval;

	if (ctx->level != SOL_IP || ctx->optname != IP_TOS)
		return 1;

	if (optval + 1 > optval_end)
		return 0; /* EPERM, bounds check */

	optval[0] += 0x10;
	ctx->optlen = 1;

	return 1;
}