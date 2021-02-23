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
typedef  int /*<<< orphan*/  MYSQLND_VIO ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_ENTER (char*) ; 
 int /*<<< orphan*/  DBG_INF_FMT (char*,unsigned int const) ; 
 int /*<<< orphan*/  DBG_RETURN (void*) ; 
 unsigned int const mysqlnd_plugin_count () ; 

__attribute__((used)) static void **
mysqlnd_plugin__get_plugin_vio_data(const MYSQLND_VIO * vio, const unsigned int plugin_id)
{
	DBG_ENTER("_mysqlnd_plugin__get_plugin_vio_data");
	DBG_INF_FMT("plugin_id=%u", plugin_id);
	if (!vio || plugin_id >= mysqlnd_plugin_count()) {
		return NULL;
	}
	DBG_RETURN((void *)((char *)vio + sizeof(MYSQLND_VIO) + plugin_id * sizeof(void *)));
}