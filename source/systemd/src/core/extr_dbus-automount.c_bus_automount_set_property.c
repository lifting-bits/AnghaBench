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
typedef  char const sd_bus_message ;
typedef  int /*<<< orphan*/  sd_bus_error ;
typedef  int /*<<< orphan*/  UnitWriteFlags ;
struct TYPE_4__ {scalar_t__ load_state; scalar_t__ transient; } ;
typedef  TYPE_1__ Unit ;
typedef  char const Automount ;

/* Variables and functions */
 char* AUTOMOUNT (TYPE_1__*) ; 
 scalar_t__ UNIT_STUB ; 
 int /*<<< orphan*/  assert (char const*) ; 
 int bus_automount_set_transient_property (char const*,char const*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int bus_automount_set_property(
                Unit *u,
                const char *name,
                sd_bus_message *message,
                UnitWriteFlags flags,
                sd_bus_error *error) {

        Automount *a = AUTOMOUNT(u);

        assert(a);
        assert(name);
        assert(message);

        if (u->transient && u->load_state == UNIT_STUB) /* This is a transient unit? let's load a little more */
                return bus_automount_set_transient_property(a, name, message, flags, error);

        return 0;
}