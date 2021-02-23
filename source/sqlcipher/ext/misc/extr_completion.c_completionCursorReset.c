#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ j; scalar_t__ pStmt; scalar_t__ nLine; scalar_t__ zLine; scalar_t__ nPrefix; scalar_t__ zPrefix; } ;
typedef  TYPE_1__ completion_cursor ;

/* Variables and functions */
 int /*<<< orphan*/  sqlite3_finalize (scalar_t__) ; 
 int /*<<< orphan*/  sqlite3_free (scalar_t__) ; 

__attribute__((used)) static void completionCursorReset(completion_cursor *pCur){
  sqlite3_free(pCur->zPrefix);   pCur->zPrefix = 0;  pCur->nPrefix = 0;
  sqlite3_free(pCur->zLine);     pCur->zLine = 0;    pCur->nLine = 0;
  sqlite3_finalize(pCur->pStmt); pCur->pStmt = 0;
  pCur->j = 0;
}