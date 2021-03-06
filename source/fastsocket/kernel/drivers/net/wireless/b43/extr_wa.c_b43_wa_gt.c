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
struct TYPE_2__ {int rev; } ;
struct b43_wldev {TYPE_1__ phy; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_OFDMTAB_GAIN0 ; 
 int /*<<< orphan*/  B43_OFDMTAB_GAIN1 ; 
 int /*<<< orphan*/  B43_OFDMTAB_GAIN2 ; 
 int /*<<< orphan*/  b43_ofdmtab_write16 (struct b43_wldev*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void b43_wa_gt(struct b43_wldev *dev) /* Gain table. */
{
	if (dev->phy.rev <= 2) {
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN2, 0, 15);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN2, 1, 31);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN2, 2, 42);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN2, 3, 48);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN2, 4, 58);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 0, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 1, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 2, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 3, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 4, 21);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 5, 21);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 6, 25);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN1, 0, 3);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN1, 1, 3);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN1, 2, 7);
	} else {
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 0, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 1, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 2, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 3, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 4, 21);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 5, 21);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_GAIN0, 6, 25);
	}
}