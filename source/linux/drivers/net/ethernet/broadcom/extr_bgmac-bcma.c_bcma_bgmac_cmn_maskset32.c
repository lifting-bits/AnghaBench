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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_2__ {int /*<<< orphan*/  cmn; } ;
struct bgmac {TYPE_1__ bcma; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcma_maskset32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bcma_bgmac_cmn_maskset32(struct bgmac *bgmac, u16 offset, u32 mask,
				     u32 set)
{
	bcma_maskset32(bgmac->bcma.cmn, offset, mask, set);
}