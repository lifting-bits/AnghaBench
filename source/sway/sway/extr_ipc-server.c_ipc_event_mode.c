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
typedef  int /*<<< orphan*/  json_object ;

/* Variables and functions */
 int /*<<< orphan*/  IPC_EVENT_MODE ; 
 int /*<<< orphan*/  SWAY_DEBUG ; 
 int /*<<< orphan*/  ipc_has_event_listeners (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipc_send_event (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  json_object_new_boolean (int) ; 
 int /*<<< orphan*/ * json_object_new_object () ; 
 int /*<<< orphan*/  json_object_new_string (char const*) ; 
 int /*<<< orphan*/  json_object_object_add (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  json_object_put (int /*<<< orphan*/ *) ; 
 char* json_object_to_json_string (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,char const*) ; 

void ipc_event_mode(const char *mode, bool pango) {
	if (!ipc_has_event_listeners(IPC_EVENT_MODE)) {
		return;
	}
	sway_log(SWAY_DEBUG, "Sending mode::%s event", mode);
	json_object *obj = json_object_new_object();
	json_object_object_add(obj, "change", json_object_new_string(mode));
	json_object_object_add(obj, "pango_markup",
			json_object_new_boolean(pango));

	const char *json_string = json_object_to_json_string(obj);
	ipc_send_event(json_string, IPC_EVENT_MODE);
	json_object_put(obj);
}