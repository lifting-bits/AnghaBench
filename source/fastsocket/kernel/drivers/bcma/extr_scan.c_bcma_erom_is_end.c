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
typedef  int u32 ;
struct bcma_bus {int dummy; } ;

/* Variables and functions */
 int SCAN_ER_TAG_END ; 
 int SCAN_ER_VALID ; 
 int bcma_erom_get_ent (struct bcma_bus*,int**) ; 
 int /*<<< orphan*/  bcma_erom_push_ent (int**) ; 

__attribute__((used)) static bool bcma_erom_is_end(struct bcma_bus *bus, u32 **eromptr)
{
	u32 ent = bcma_erom_get_ent(bus, eromptr);
	bcma_erom_push_ent(eromptr);
	return (ent == (SCAN_ER_TAG_END | SCAN_ER_VALID));
}