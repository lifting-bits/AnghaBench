#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int idx; scalar_t__ instack; } ;
typedef  TYPE_2__ Upvaldesc ;
struct TYPE_11__ {int /*<<< orphan*/ * v; } ;
typedef  TYPE_3__ UpVal ;
struct TYPE_13__ {TYPE_1__** upvals; } ;
struct TYPE_12__ {int sizeupvalues; TYPE_2__* upvalues; TYPE_5__* cache; } ;
struct TYPE_9__ {int /*<<< orphan*/ * v; } ;
typedef  int /*<<< orphan*/  TValue ;
typedef  int /*<<< orphan*/ * StkId ;
typedef  TYPE_4__ Proto ;
typedef  TYPE_5__ LClosure ;

/* Variables and functions */

__attribute__((used)) static LClosure *getcached (Proto *p, UpVal **encup, StkId base) {
  LClosure *c = p->cache;
  if (c != NULL) {  /* is there a cached closure? */
    int nup = p->sizeupvalues;
    Upvaldesc *uv = p->upvalues;
    int i;
    for (i = 0; i < nup; i++) {  /* check whether it has right upvalues */
      TValue *v = uv[i].instack ? base + uv[i].idx : encup[uv[i].idx]->v;
      if (c->upvals[i]->v != v)
        return NULL;  /* wrong upvalue; cannot reuse closure */
    }
  }
  return c;  /* return cached closure (or NULL if no cached closure) */
}