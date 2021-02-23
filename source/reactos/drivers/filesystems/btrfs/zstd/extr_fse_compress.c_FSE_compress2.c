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
typedef  int /*<<< orphan*/  fseWkspMax_t ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_STATIC_ASSERT (int) ; 
 size_t ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ExAllocatePoolWithTag (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreePool (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FSEC_ALLOC_TAG ; 
 int /*<<< orphan*/  FSE_MAX_SYMBOL_VALUE ; 
 unsigned int FSE_MAX_TABLELOG ; 
 int FSE_WKSP_SIZE_U32 (unsigned int,int /*<<< orphan*/ ) ; 
 size_t FSE_compress_wksp (void*,size_t,void const*,size_t,unsigned int,unsigned int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  NonPagedPool ; 
 int /*<<< orphan*/  tableLog_tooLarge ; 

size_t FSE_compress2 (void* dst, size_t dstCapacity, const void* src, size_t srcSize, unsigned maxSymbolValue, unsigned tableLog)
{
    fseWkspMax_t* scratchBuffer;
    size_t ret;

    DEBUG_STATIC_ASSERT(sizeof(fseWkspMax_t) >= FSE_WKSP_SIZE_U32(FSE_MAX_TABLELOG, FSE_MAX_SYMBOL_VALUE));   /* compilation failures here means scratchBuffer is not large enough */

    if (tableLog > FSE_MAX_TABLELOG)
        return ERROR(tableLog_tooLarge);

    scratchBuffer = ExAllocatePoolWithTag(NonPagedPool, sizeof(fseWkspMax_t), FSEC_ALLOC_TAG);

    if (!scratchBuffer)
        return 0;

    ret = FSE_compress_wksp(dst, dstCapacity, src, srcSize, maxSymbolValue, tableLog, scratchBuffer, sizeof(fseWkspMax_t));

    ExFreePool(scratchBuffer);

    return ret;
}