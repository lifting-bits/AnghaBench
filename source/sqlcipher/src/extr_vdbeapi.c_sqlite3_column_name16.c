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
typedef  int /*<<< orphan*/  sqlite3_stmt ;

/* Variables and functions */
 int /*<<< orphan*/  COLNAME_NAME ; 
 void const* columnName (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 

const void *sqlite3_column_name16(sqlite3_stmt *pStmt, int N){
  return columnName(pStmt, N, 1, COLNAME_NAME);
}