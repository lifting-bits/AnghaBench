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
typedef  int /*<<< orphan*/  gchar ;
typedef  int /*<<< orphan*/  GhbValue ;

/* Variables and functions */
 int /*<<< orphan*/ * g_strdup (char*) ; 
 int /*<<< orphan*/ * ghb_dict_get_value (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * ghb_value_get_string_xform (int /*<<< orphan*/  const*) ; 

gchar*
ghb_dict_get_string_xform(const GhbValue *dict, const gchar *key)
{
    const GhbValue* value;
    value = ghb_dict_get_value(dict, key);
    if (value == NULL) return g_strdup("");
    return ghb_value_get_string_xform(value);
}