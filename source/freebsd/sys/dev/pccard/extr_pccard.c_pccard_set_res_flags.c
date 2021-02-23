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
typedef  int /*<<< orphan*/  u_long ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int CARD_SET_RES_FLAGS (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
pccard_set_res_flags(device_t dev, device_t child, int type, int rid,
    u_long flags)
{
	return (CARD_SET_RES_FLAGS(device_get_parent(dev), child, type,
	    rid, flags));
}