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
typedef  scalar_t__ uint64_t ;
typedef  size_t uint32_t ;
struct TYPE_3__ {size_t* FolderStartPackStreamIndex; scalar_t__* PackStreamStartPositions; scalar_t__ dataPos; } ;
typedef  TYPE_1__ CSzArEx ;

/* Variables and functions */

uint64_t SzArEx_GetFolderStreamPos(const CSzArEx *p, uint32_t folderIndex, uint32_t indexInFolder)
{
   return p->dataPos +
      p->PackStreamStartPositions[p->FolderStartPackStreamIndex[folderIndex] + indexInFolder];
}