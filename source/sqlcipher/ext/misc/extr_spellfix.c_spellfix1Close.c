#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sqlite3_vtab_cursor ;
struct TYPE_5__ {struct TYPE_5__* zPattern; } ;
typedef  TYPE_1__ spellfix1_cursor ;

/* Variables and functions */
 int SQLITE_OK ; 
 int /*<<< orphan*/  spellfix1ResetCursor (TYPE_1__*) ; 
 int /*<<< orphan*/  spellfix1ResizeCursor (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_free (TYPE_1__*) ; 

__attribute__((used)) static int spellfix1Close(sqlite3_vtab_cursor *cur){
  spellfix1_cursor *pCur = (spellfix1_cursor *)cur;
  spellfix1ResetCursor(pCur);
  spellfix1ResizeCursor(pCur, 0);
  sqlite3_free(pCur->zPattern);
  sqlite3_free(pCur);
  return SQLITE_OK;
}