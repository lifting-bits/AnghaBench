#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ windowLog; } ;
typedef  TYPE_1__ ZSTD_parameters ;
typedef  scalar_t__ U32 ;
typedef  int BYTE ;

/* Variables and functions */
 size_t ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ MEM_readLE32 (void const*) ; 
 scalar_t__ ZSTD_MAGICNUMBER ; 
 scalar_t__ ZSTD_WINDOWLOG_ABSOLUTEMIN ; 
 size_t ZSTD_frameHeaderSize_max ; 
 size_t ZSTD_frameHeaderSize_min ; 
 int /*<<< orphan*/  frameParameter_unsupported ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  prefix_unknown ; 

__attribute__((used)) static size_t ZSTD_getFrameParams(ZSTD_parameters* params, const void* src, size_t srcSize)
{
    U32 magicNumber;
    if (srcSize < ZSTD_frameHeaderSize_min) return ZSTD_frameHeaderSize_max;
    magicNumber = MEM_readLE32(src);
    if (magicNumber != ZSTD_MAGICNUMBER) return ERROR(prefix_unknown);
    memset(params, 0, sizeof(*params));
    params->windowLog = (((const BYTE*)src)[4] & 15) + ZSTD_WINDOWLOG_ABSOLUTEMIN;
    if ((((const BYTE*)src)[4] >> 4) != 0) return ERROR(frameParameter_unsupported);   /* reserved bits */
    return 0;
}