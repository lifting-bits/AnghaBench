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
typedef  int /*<<< orphan*/  MYSQLND_PFC ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_ENTER (char*) ; 
 int /*<<< orphan*/  DBG_INF_FMT (char*,unsigned int const) ; 
 int /*<<< orphan*/  DBG_RETURN (void*) ; 
 unsigned int const mysqlnd_plugin_count () ; 

__attribute__((used)) static void **
mysqlnd_plugin__get_plugin_pfc_data(const MYSQLND_PFC * pfc, const unsigned int plugin_id)
{
	DBG_ENTER("mysqlnd_plugin__get_plugin_pfc_data");
	DBG_INF_FMT("plugin_id=%u", plugin_id);
	if (!pfc || plugin_id >= mysqlnd_plugin_count()) {
		return NULL;
	}
	DBG_RETURN((void *)((char *)pfc + sizeof(MYSQLND_PFC) + plugin_id * sizeof(void *)));
}