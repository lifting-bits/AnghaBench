#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {TYPE_2__* pOut; } ;
typedef  TYPE_3__ sqlite3_context ;
struct TYPE_7__ {TYPE_1__* db; } ;
struct TYPE_6__ {int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  setResultStrOrError (TYPE_3__*,void const*,int,int /*<<< orphan*/ ,void (*) (void*)) ; 
 int sqlite3_mutex_held (int /*<<< orphan*/ ) ; 

void sqlite3_result_blob(
  sqlite3_context *pCtx,
  const void *z,
  int n,
  void (*xDel)(void *)
){
  assert( n>=0 );
  assert( sqlite3_mutex_held(pCtx->pOut->db->mutex) );
  setResultStrOrError(pCtx, z, n, 0, xDel);
}