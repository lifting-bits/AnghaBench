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
typedef  int /*<<< orphan*/  sqlite3_vtab_cursor ;
struct TYPE_4__ {int /*<<< orphan*/  pStmt; int /*<<< orphan*/  term; } ;
typedef  TYPE_1__ Fts5VocabCursor ;

/* Variables and functions */
 int SQLITE_OK ; 
 int /*<<< orphan*/  fts5VocabResetCursor (TYPE_1__*) ; 
 int /*<<< orphan*/  sqlite3Fts5BufferFree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqlite3_finalize (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_free (TYPE_1__*) ; 

__attribute__((used)) static int fts5VocabCloseMethod(sqlite3_vtab_cursor *pCursor){
  Fts5VocabCursor *pCsr = (Fts5VocabCursor*)pCursor;
  fts5VocabResetCursor(pCsr);
  sqlite3Fts5BufferFree(&pCsr->term);
  sqlite3_finalize(pCsr->pStmt);
  sqlite3_free(pCsr);
  return SQLITE_OK;
}