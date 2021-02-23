#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_12__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ Sqlite ;
typedef  TYPE_2__ Error ;

/* Variables and functions */
 int /*<<< orphan*/  SQLITE_LOCKED ; 
 int /*<<< orphan*/  clear_error (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  closedb (TYPE_2__*,TYPE_1__*) ; 
 int /*<<< orphan*/  opendb (TYPE_2__*,TYPE_1__*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  print_and_free_err (TYPE_2__*) ; 
 int /*<<< orphan*/  sql_script (TYPE_2__*,TYPE_1__*,char*) ; 
 char* sqlite3_mprintf (char*) ; 
 int /*<<< orphan*/  timetostop (TYPE_2__*) ; 

__attribute__((used)) static char *stress2_workload19(int iTid, void *pArg){
  Error err = {0};                /* Error code and message */
  Sqlite db = {0};                /* SQLite database connection */
  const char *zDb = (const char*)pArg;
  while( !timetostop(&err) ){
    opendb(&err, &db, zDb, 0);
    sql_script(&err, &db, "SELECT * FROM sqlite_master;");
    clear_error(&err, SQLITE_LOCKED);
    closedb(&err, &db);
  }
  print_and_free_err(&err);
  return sqlite3_mprintf("ok");
}