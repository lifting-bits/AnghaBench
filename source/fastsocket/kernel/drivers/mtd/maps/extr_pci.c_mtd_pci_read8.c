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
struct map_pci_info {scalar_t__ (* translate ) (struct map_pci_info*,unsigned long) ;scalar_t__ base; } ;
struct map_info {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/ * x; } ;
typedef  TYPE_1__ map_word ;

/* Variables and functions */
 int /*<<< orphan*/  readb (scalar_t__) ; 
 scalar_t__ stub1 (struct map_pci_info*,unsigned long) ; 

__attribute__((used)) static map_word mtd_pci_read8(struct map_info *_map, unsigned long ofs)
{
	struct map_pci_info *map = (struct map_pci_info *)_map;
	map_word val;
	val.x[0]= readb(map->base + map->translate(map, ofs));
//	printk("read8 : %08lx => %02x\n", ofs, val.x[0]);
	return val;
}