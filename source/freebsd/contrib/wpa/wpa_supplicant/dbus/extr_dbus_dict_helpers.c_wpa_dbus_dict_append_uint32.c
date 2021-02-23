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
typedef  int /*<<< orphan*/  dbus_uint32_t ;
typedef  int /*<<< orphan*/  dbus_bool_t ;
typedef  int /*<<< orphan*/  DBusMessageIter ;

/* Variables and functions */
 int /*<<< orphan*/  DBUS_TYPE_UINT32 ; 
 int /*<<< orphan*/  _wpa_dbus_add_dict_entry_basic (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 

dbus_bool_t wpa_dbus_dict_append_uint32(DBusMessageIter *iter_dict,
					const char *key,
					const dbus_uint32_t value)
{
	return _wpa_dbus_add_dict_entry_basic(iter_dict, key, DBUS_TYPE_UINT32,
					      &value);
}