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
typedef  int /*<<< orphan*/  isc_uint8_t ;
typedef  int /*<<< orphan*/  isc_sha512_t ;
typedef  int /*<<< orphan*/  isc_sha384_t ;

/* Variables and functions */
 int /*<<< orphan*/  isc_sha512_update (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,size_t) ; 

void
isc_sha384_update(isc_sha384_t *context, const isc_uint8_t* data, size_t len) {
	isc_sha512_update((isc_sha512_t *)context, data, len);
}