#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  entity_t ;
struct TYPE_10__ {struct TYPE_10__* next; } ;
typedef  TYPE_1__ bspbrush_t ;

/* Variables and functions */
 int /*<<< orphan*/  FreeBrush (TYPE_1__*) ; 
 int /*<<< orphan*/  HL_BSPBrushToMapBrush (TYPE_1__*,int /*<<< orphan*/ *) ; 
 TYPE_1__* HL_CreateBrushesFromBSP (int) ; 
 int /*<<< orphan*/  HL_FixContentsTextures (TYPE_1__*) ; 
 TYPE_1__* HL_MergeBrushes (TYPE_1__*,int) ; 
 TYPE_1__* HL_TextureBrushes (TYPE_1__*,int) ; 
 int /*<<< orphan*/  nobrushmerge ; 
 int /*<<< orphan*/  qprintf (char*,...) ; 

void HL_CreateMapBrushes(entity_t *mapent, int modelnum)
{
	bspbrush_t *brushlist, *brush, *nextbrush;
	int i;

	//create brushes from the model BSP tree
	brushlist = HL_CreateBrushesFromBSP(modelnum);
	//texture the brushes and split them when necesary
	brushlist = HL_TextureBrushes(brushlist, modelnum);
	//fix the contents textures of all brushes
	HL_FixContentsTextures(brushlist);
	//
	if (!nobrushmerge)
	{
		brushlist = HL_MergeBrushes(brushlist, modelnum);
		//brushlist = HL_MergeBrushes(brushlist, modelnum);
	} //end if
	//
	if (!modelnum) qprintf("converting brushes to map brushes\n");
	if (!modelnum) qprintf("%5d brushes", i = 0);
	for (brush = brushlist; brush; brush = nextbrush)
	{
		nextbrush = brush->next;
		HL_BSPBrushToMapBrush(brush, mapent);
		brush->next = NULL;
		FreeBrush(brush);
		if (!modelnum) qprintf("\r%5d", ++i);
	} //end for
	if (!modelnum) qprintf("\n");
}