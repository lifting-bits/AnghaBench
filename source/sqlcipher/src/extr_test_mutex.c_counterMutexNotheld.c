#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  pReal; } ;
typedef  TYPE_2__ sqlite3_mutex ;
struct TYPE_5__ {int (* xMutexNotheld ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_7__ {TYPE_1__ m; } ;

/* Variables and functions */
 TYPE_3__ g ; 
 int stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int counterMutexNotheld(sqlite3_mutex *p){
  return g.m.xMutexNotheld(p->pReal);
}