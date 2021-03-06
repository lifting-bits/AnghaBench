#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sqlite3_stmt ;
struct TYPE_5__ {TYPE_1__* db; int /*<<< orphan*/ * aVar; } ;
typedef  TYPE_2__ Vdbe ;
struct TYPE_4__ {int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int SQLITE_OK ; 
 int /*<<< orphan*/  sqlite3VdbeMemSetPointer (int /*<<< orphan*/ *,void*,char const*,void (*) (void*)) ; 
 int /*<<< orphan*/  sqlite3_mutex_leave (int /*<<< orphan*/ ) ; 
 int vdbeUnbind (TYPE_2__*,int) ; 

int sqlite3_bind_pointer(
  sqlite3_stmt *pStmt,
  int i,
  void *pPtr,
  const char *zPTtype,
  void (*xDestructor)(void*)
){
  int rc;
  Vdbe *p = (Vdbe*)pStmt;
  rc = vdbeUnbind(p, i);
  if( rc==SQLITE_OK ){
    sqlite3VdbeMemSetPointer(&p->aVar[i-1], pPtr, zPTtype, xDestructor);
    sqlite3_mutex_leave(p->db->mutex);
  }else if( xDestructor ){
    xDestructor(pPtr);
  }
  return rc;
}