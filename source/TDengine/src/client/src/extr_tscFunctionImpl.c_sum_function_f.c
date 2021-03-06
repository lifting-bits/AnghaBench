#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  int32_t ;
struct TYPE_10__ {scalar_t__ aOutputBuf; } ;
struct TYPE_9__ {scalar_t__ hasResult; scalar_t__ superTableQ; } ;
struct TYPE_8__ {scalar_t__ hasResult; } ;
typedef  TYPE_1__ SSumInfo ;
typedef  TYPE_2__ SResultInfo ;
typedef  TYPE_3__ SQLFunctionCtx ;

/* Variables and functions */
 scalar_t__ DATA_SET_FLAG ; 
 TYPE_2__* GET_RES_INFO (TYPE_3__*) ; 
 int /*<<< orphan*/  do_sum_f (TYPE_3__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sum_function_f(SQLFunctionCtx *pCtx, int32_t index) {
  do_sum_f(pCtx, index);

  // keep the result data in output buffer, not in the intermediate buffer
  SResultInfo *pResInfo = GET_RES_INFO(pCtx);
  if (pResInfo->hasResult == DATA_SET_FLAG && pResInfo->superTableQ) {
    SSumInfo *pSum = (SSumInfo *)pCtx->aOutputBuf;
    pSum->hasResult = DATA_SET_FLAG;
  }
}