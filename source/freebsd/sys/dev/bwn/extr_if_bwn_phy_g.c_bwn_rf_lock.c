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
struct bwn_mac {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BWN_MACCTL ; 
 int BWN_MACCTL_RADIO_LOCK ; 
 int BWN_READ_4 (struct bwn_mac*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BWN_WRITE_4 (struct bwn_mac*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DELAY (int) ; 

__attribute__((used)) static void
bwn_rf_lock(struct bwn_mac *mac)
{

	BWN_WRITE_4(mac, BWN_MACCTL,
	    BWN_READ_4(mac, BWN_MACCTL) | BWN_MACCTL_RADIO_LOCK);
	BWN_READ_4(mac, BWN_MACCTL);
	DELAY(10);
}