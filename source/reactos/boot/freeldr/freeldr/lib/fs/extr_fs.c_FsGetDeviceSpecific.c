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
typedef  int /*<<< orphan*/  VOID ;
typedef  size_t ULONG ;
struct TYPE_2__ {int /*<<< orphan*/ * Specific; int /*<<< orphan*/  FuncTable; } ;

/* Variables and functions */
 TYPE_1__* FileData ; 
 size_t MAX_FDS ; 

VOID* FsGetDeviceSpecific(ULONG FileId)
{
    if (FileId >= MAX_FDS || !FileData[FileId].FuncTable)
        return NULL;
    return FileData[FileId].Specific;
}