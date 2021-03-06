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
typedef  scalar_t__ U32 ;
struct TYPE_2__ {scalar_t__ fastMode; } ;
typedef  TYPE_1__ FSEv07_DTableHeader ;
typedef  int /*<<< orphan*/  FSEv07_DTable ;

/* Variables and functions */
 size_t FSEv07_decompress_usingDTable_generic (void*,size_t,void const*,size_t,int /*<<< orphan*/  const*,int) ; 

size_t FSEv07_decompress_usingDTable(void* dst, size_t originalSize,
                            const void* cSrc, size_t cSrcSize,
                            const FSEv07_DTable* dt)
{
    const void* ptr = dt;
    const FSEv07_DTableHeader* DTableH = (const FSEv07_DTableHeader*)ptr;
    const U32 fastMode = DTableH->fastMode;

    /* select fast mode (static) */
    if (fastMode) return FSEv07_decompress_usingDTable_generic(dst, originalSize, cSrc, cSrcSize, dt, 1);
    return FSEv07_decompress_usingDTable_generic(dst, originalSize, cSrc, cSrcSize, dt, 0);
}