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
typedef  int /*<<< orphan*/  lu_mem ;
struct TYPE_13__ {scalar_t__ gcstate; } ;
typedef  TYPE_3__ global_State ;
struct TYPE_11__ {int touched; } ;
struct TYPE_12__ {TYPE_1__ open; } ;
struct TYPE_14__ {int /*<<< orphan*/  v; TYPE_2__ u; } ;
typedef  TYPE_4__ UpVal ;
struct TYPE_15__ {int nupvalues; TYPE_4__** upvals; int /*<<< orphan*/  p; } ;
typedef  TYPE_5__ LClosure ;

/* Variables and functions */
 scalar_t__ GCSinsideatomic ; 
 int /*<<< orphan*/  markobjectN (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  markvalue (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sizeLclosure (int) ; 
 scalar_t__ upisopen (TYPE_4__*) ; 

__attribute__((used)) static lu_mem traverseLclosure (global_State *g, LClosure *cl) {
  int i;
  markobjectN(g, cl->p);  /* mark its prototype */
  for (i = 0; i < cl->nupvalues; i++) {  /* mark its upvalues */
    UpVal *uv = cl->upvals[i];
    if (uv != NULL) {
      if (upisopen(uv) && g->gcstate != GCSinsideatomic)
        uv->u.open.touched = 1;  /* can be marked in 'remarkupvals' */
      else
        markvalue(g, uv->v);
    }
  }
  return sizeLclosure(cl->nupvalues);
}