#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int guint ;
struct TYPE_2__ {void* group; void* keyfile; } ;
typedef  int /*<<< orphan*/  GValue ;
typedef  int /*<<< orphan*/  GParamSpec ;
typedef  int /*<<< orphan*/  GObject ;

/* Variables and functions */
#define  PROP_GROUP 129 
#define  PROP_KEYFILE 128 
 TYPE_1__* YUI_RESOLUTION (int /*<<< orphan*/ *) ; 
 void* g_value_get_pointer (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static void yui_resolution_set_property(GObject * object, guint property_id,
		const GValue * value, GParamSpec * pspec) {
	switch(property_id) {
		case PROP_KEYFILE:
			YUI_RESOLUTION(object)->keyfile = g_value_get_pointer(value);
			break;
		case PROP_GROUP:
			YUI_RESOLUTION(object)->group = g_value_get_pointer(value);
			break;
	}
}