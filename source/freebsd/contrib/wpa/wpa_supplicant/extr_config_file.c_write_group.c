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
struct wpa_ssid {scalar_t__ group_cipher; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ DEFAULT_GROUP ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  os_free (char*) ; 
 char* wpa_config_get (struct wpa_ssid*,char*) ; 

__attribute__((used)) static void write_group(FILE *f, struct wpa_ssid *ssid)
{
	char *value;

	if (ssid->group_cipher == DEFAULT_GROUP)
		return;

	value = wpa_config_get(ssid, "group");
	if (value == NULL)
		return;
	if (value[0])
		fprintf(f, "\tgroup=%s\n", value);
	os_free(value);
}