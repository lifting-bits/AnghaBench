#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_1__* db; } ;
struct TYPE_6__ {TYPE_4__ s; int /*<<< orphan*/  isError; } ;
typedef  TYPE_2__ sqlite3_context ;
struct TYPE_5__ {int mallocFailed; int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  SQLITE_NOMEM ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3VdbeMemSetNull (TYPE_4__*) ; 
 int /*<<< orphan*/  sqlite3_mutex_held (int /*<<< orphan*/ ) ; 

void sqlite3_result_error_nomem(sqlite3_context *pCtx){
  assert( sqlite3_mutex_held(pCtx->s.db->mutex) );
  sqlite3VdbeMemSetNull(&pCtx->s);
  pCtx->isError = SQLITE_NOMEM;
  pCtx->s.db->mallocFailed = 1;
}