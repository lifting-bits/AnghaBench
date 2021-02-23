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
typedef  int /*<<< orphan*/  lsm_env ;
struct TYPE_4__ {int iPg; struct TYPE_4__* aPg; int /*<<< orphan*/  blob; int /*<<< orphan*/  pPage; int /*<<< orphan*/  pFS; } ;
typedef  TYPE_1__ BtreeCursor ;

/* Variables and functions */
 int /*<<< orphan*/  lsmFree (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/ * lsmFsEnv (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lsmFsPageRelease (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sortedBlobFree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void btreeCursorFree(BtreeCursor *pCsr){
  if( pCsr ){
    int i;
    lsm_env *pEnv = lsmFsEnv(pCsr->pFS);
    for(i=0; i<=pCsr->iPg; i++){
      lsmFsPageRelease(pCsr->aPg[i].pPage);
    }
    sortedBlobFree(&pCsr->blob);
    lsmFree(pEnv, pCsr->aPg);
    lsmFree(pEnv, pCsr);
  }
}