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
typedef  int /*<<< orphan*/  libusb_context ;

/* Variables and functions */
 int libusb_handle_events_timeout_completed (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 

int
libusb_handle_events_completed(libusb_context *ctx, int *completed)
{
	return (libusb_handle_events_timeout_completed(ctx, NULL, completed));
}