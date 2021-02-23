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
struct TYPE_4__ {struct TYPE_4__* apExprPhrase; int /*<<< orphan*/  pRoot; } ;
typedef  TYPE_1__ Fts5Expr ;

/* Variables and functions */
 int /*<<< orphan*/  sqlite3Fts5ParseNodeFree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_free (TYPE_1__*) ; 

void sqlite3Fts5ExprFree(Fts5Expr *p){
  if( p ){
    sqlite3Fts5ParseNodeFree(p->pRoot);
    sqlite3_free(p->apExprPhrase);
    sqlite3_free(p);
  }
}