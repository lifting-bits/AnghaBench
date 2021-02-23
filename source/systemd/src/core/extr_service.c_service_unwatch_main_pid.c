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
struct TYPE_5__ {scalar_t__ main_pid; } ;
typedef  TYPE_1__ Service ;

/* Variables and functions */
 int /*<<< orphan*/  UNIT (TYPE_1__*) ; 
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int /*<<< orphan*/  unit_unwatch_pid (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void service_unwatch_main_pid(Service *s) {
        assert(s);

        if (s->main_pid <= 0)
                return;

        unit_unwatch_pid(UNIT(s), s->main_pid);
        s->main_pid = 0;
}