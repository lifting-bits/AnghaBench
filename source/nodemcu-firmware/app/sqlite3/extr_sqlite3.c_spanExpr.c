#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
struct TYPE_12__ {int n; int /*<<< orphan*/ * z; } ;
typedef  TYPE_2__ Token ;
struct TYPE_11__ {char* zToken; } ;
struct TYPE_15__ {int iAgg; int nHeight; TYPE_1__ u; int /*<<< orphan*/  flags; scalar_t__ op; } ;
struct TYPE_14__ {int /*<<< orphan*/ * zEnd; int /*<<< orphan*/ * zStart; TYPE_5__* pExpr; } ;
struct TYPE_13__ {int /*<<< orphan*/  db; } ;
typedef  TYPE_3__ Parse ;
typedef  TYPE_4__ ExprSpan ;
typedef  TYPE_5__ Expr ;

/* Variables and functions */
 int /*<<< orphan*/  EP_DblQuoted ; 
 int /*<<< orphan*/  EP_Leaf ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 TYPE_5__* sqlite3DbMallocRawNN (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sqlite3Dequote (char*) ; 
 scalar_t__ sqlite3Isquote (char) ; 

__attribute__((used)) static void spanExpr(ExprSpan *pOut, Parse *pParse, int op, Token t){
    Expr *p = sqlite3DbMallocRawNN(pParse->db, sizeof(Expr)+t.n+1);
    if( p ){
      memset(p, 0, sizeof(Expr));
      p->op = (u8)op;
      p->flags = EP_Leaf;
      p->iAgg = -1;
      p->u.zToken = (char*)&p[1];
      memcpy(p->u.zToken, t.z, t.n);
      p->u.zToken[t.n] = 0;
      if( sqlite3Isquote(p->u.zToken[0]) ){
        if( p->u.zToken[0]=='"' ) p->flags |= EP_DblQuoted;
        sqlite3Dequote(p->u.zToken);
      }
#if SQLITE_MAX_EXPR_DEPTH>0
      p->nHeight = 1;
#endif
    }
    pOut->pExpr = p;
    pOut->zStart = t.z;
    pOut->zEnd = &t.z[t.n];
  }