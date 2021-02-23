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
typedef  int /*<<< orphan*/  u8 ;
struct p2p_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/ * p2p_get_device (struct p2p_data*,int /*<<< orphan*/  const*) ; 

int p2p_peer_known(struct p2p_data *p2p, const u8 *addr)
{
	return p2p_get_device(p2p, addr) != NULL;
}