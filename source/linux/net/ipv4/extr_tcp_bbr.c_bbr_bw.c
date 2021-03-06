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
typedef  int /*<<< orphan*/  u32 ;
struct sock {int dummy; } ;
struct bbr {int /*<<< orphan*/  lt_bw; scalar_t__ lt_use_bw; } ;

/* Variables and functions */
 int /*<<< orphan*/  bbr_max_bw (struct sock const*) ; 
 struct bbr* inet_csk_ca (struct sock const*) ; 

__attribute__((used)) static u32 bbr_bw(const struct sock *sk)
{
	struct bbr *bbr = inet_csk_ca(sk);

	return bbr->lt_use_bw ? bbr->lt_bw : bbr_max_bw(sk);
}