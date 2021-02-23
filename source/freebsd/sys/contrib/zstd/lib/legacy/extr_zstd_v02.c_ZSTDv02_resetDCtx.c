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
typedef  int /*<<< orphan*/  ZSTDv02_Dctx ;
typedef  int /*<<< orphan*/  ZSTD_DCtx ;

/* Variables and functions */
 size_t ZSTD_resetDCtx (int /*<<< orphan*/ *) ; 

size_t ZSTDv02_resetDCtx(ZSTDv02_Dctx* dctx)
{
    return ZSTD_resetDCtx((ZSTD_DCtx*)dctx);
}