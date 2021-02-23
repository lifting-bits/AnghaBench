#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/ * data; int /*<<< orphan*/  polkit_registry; } ;
typedef  TYPE_1__ sd_bus_message ;
typedef  int /*<<< orphan*/  sd_bus_error ;
typedef  TYPE_1__ Context ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 size_t PROP_STATIC_HOSTNAME ; 
 int /*<<< orphan*/  SD_BUS_ERROR_INVALID_ARGS ; 
 int /*<<< orphan*/  UID_INVALID ; 
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int bus_verify_polkit_async (TYPE_1__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int context_update_kernel_hostname (TYPE_1__*) ; 
 int context_write_data_static_hostname (TYPE_1__*) ; 
 char* empty_to_null (char const*) ; 
 int free_and_strdup (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  hostname_is_valid (char const*,int) ; 
 int /*<<< orphan*/  isempty (char const*) ; 
 int /*<<< orphan*/  log_error_errno (int,char*) ; 
 int /*<<< orphan*/  log_info (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sd_bus_emit_properties_changed (int /*<<< orphan*/ ,char*,char*,char*,int /*<<< orphan*/ *) ; 
 int sd_bus_error_set_errnof (int /*<<< orphan*/ *,int,char*) ; 
 int sd_bus_error_setf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  sd_bus_message_get_bus (TYPE_1__*) ; 
 int sd_bus_message_read (TYPE_1__*,char*,char const**,int*) ; 
 int sd_bus_reply_method_return (TYPE_1__*,int /*<<< orphan*/ *) ; 
 scalar_t__ streq_ptr (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strna (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int method_set_static_hostname(sd_bus_message *m, void *userdata, sd_bus_error *error) {
        Context *c = userdata;
        const char *name;
        int interactive;
        int r;

        assert(m);
        assert(c);

        r = sd_bus_message_read(m, "sb", &name, &interactive);
        if (r < 0)
                return r;

        name = empty_to_null(name);

        if (streq_ptr(name, c->data[PROP_STATIC_HOSTNAME]))
                return sd_bus_reply_method_return(m, NULL);

        if (!isempty(name) && !hostname_is_valid(name, false))
                return sd_bus_error_setf(error, SD_BUS_ERROR_INVALID_ARGS, "Invalid static hostname '%s'", name);

        r = bus_verify_polkit_async(
                        m,
                        CAP_SYS_ADMIN,
                        "org.freedesktop.hostname1.set-static-hostname",
                        NULL,
                        interactive,
                        UID_INVALID,
                        &c->polkit_registry,
                        error);
        if (r < 0)
                return r;
        if (r == 0)
                return 1; /* No authorization for now, but the async polkit stuff will call us again when it has it */

        r = free_and_strdup(&c->data[PROP_STATIC_HOSTNAME], name);
        if (r < 0)
                return r;

        r = context_update_kernel_hostname(c);
        if (r < 0) {
                log_error_errno(r, "Failed to set host name: %m");
                return sd_bus_error_set_errnof(error, r, "Failed to set hostname: %m");
        }

        r = context_write_data_static_hostname(c);
        if (r < 0) {
                log_error_errno(r, "Failed to write static host name: %m");
                return sd_bus_error_set_errnof(error, r, "Failed to set static hostname: %m");
        }

        log_info("Changed static host name to '%s'", strna(c->data[PROP_STATIC_HOSTNAME]));

        (void) sd_bus_emit_properties_changed(sd_bus_message_get_bus(m), "/org/freedesktop/hostname1", "org.freedesktop.hostname1", "StaticHostname", NULL);

        return sd_bus_reply_method_return(m, NULL);
}