#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct nouveau_fb_tile {int zcomp; TYPE_2__* tag; } ;
struct TYPE_3__ {int parts; } ;
struct nouveau_fb {int /*<<< orphan*/  tags; TYPE_1__ ram; } ;
struct TYPE_4__ {int offset; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 
 int /*<<< orphan*/  nouveau_mm_head (int /*<<< orphan*/ *,int,int,int,int,TYPE_2__**) ; 
 int round_up (int,int) ; 

void
nv40_fb_tile_comp(struct nouveau_fb *pfb, int i, u32 size, u32 flags,
		  struct nouveau_fb_tile *tile)
{
	u32 tiles = DIV_ROUND_UP(size, 0x80);
	u32 tags  = round_up(tiles / pfb->ram.parts, 0x100);
	if ( (flags & 2) &&
	    !nouveau_mm_head(&pfb->tags, 1, tags, tags, 1, &tile->tag)) {
		tile->zcomp  = 0x28000000; /* Z24S8_SPLIT_GRAD */
		tile->zcomp |= ((tile->tag->offset           ) >> 8);
		tile->zcomp |= ((tile->tag->offset + tags - 1) >> 8) << 13;
#ifdef __BIG_ENDIAN
		tile->zcomp |= 0x40000000;
#endif
	}
}