#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  sd_bus_message ;
typedef  int /*<<< orphan*/  sd_bus_error ;
typedef  int /*<<< orphan*/  sd_bus ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int sd_bus_message_enter_container (int /*<<< orphan*/ *,char,char*) ; 
 int sd_bus_message_exit_container (int /*<<< orphan*/ *) ; 
 int sd_bus_message_read (int /*<<< orphan*/ *,char*,char const**,int /*<<< orphan*/ *) ; 
 int strv_extend (void*,char const*) ; 

__attribute__((used)) static int prop_map_sessions_strv(sd_bus *bus, const char *member, sd_bus_message *m, sd_bus_error *error, void *userdata) {
        const char *name;
        int r;

        assert(bus);
        assert(m);

        r = sd_bus_message_enter_container(m, 'a', "(so)");
        if (r < 0)
                return r;

        while ((r = sd_bus_message_read(m, "(so)", &name, NULL)) > 0) {
                r = strv_extend(userdata, name);
                if (r < 0)
                        return r;
        }
        if (r < 0)
                return r;

        return sd_bus_message_exit_container(m);
}