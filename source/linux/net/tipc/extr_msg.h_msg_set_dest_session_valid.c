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
struct tipc_msg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  msg_set_bits (struct tipc_msg*,int,int,int,int) ; 

__attribute__((used)) static inline void msg_set_dest_session_valid(struct tipc_msg *m, bool valid)
{
	msg_set_bits(m, 1, 16, 0x1, valid);
}