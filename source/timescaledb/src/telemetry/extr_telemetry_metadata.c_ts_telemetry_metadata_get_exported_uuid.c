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
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 int /*<<< orphan*/  METADATA_EXPORTED_UUID_KEY_NAME ; 
 int /*<<< orphan*/  get_uuid_by_key (int /*<<< orphan*/ ) ; 

Datum
ts_telemetry_metadata_get_exported_uuid(void)
{
	return get_uuid_by_key(METADATA_EXPORTED_UUID_KEY_NAME);
}