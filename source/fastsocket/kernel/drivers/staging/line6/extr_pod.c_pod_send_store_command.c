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
struct usb_line6_pod {int /*<<< orphan*/  line6; int /*<<< orphan*/  prog_data_buf; } ;
struct usb_interface {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  POD_SYSEX_STORE ; 
 size_t SYSEX_DATA_OFS ; 
 int /*<<< orphan*/  kfree (char*) ; 
 int /*<<< orphan*/  line6_send_sysex_message (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ *,int) ; 
 char* pod_alloc_sysex_buffer (struct usb_line6_pod*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pod_resolve (char const*,short,short,char*) ; 
 struct usb_interface* to_usb_interface (struct device*) ; 
 struct usb_line6_pod* usb_get_intfdata (struct usb_interface*) ; 

__attribute__((used)) static ssize_t pod_send_store_command(struct device *dev, const char *buf, size_t count, short block0, short block1)
{
	struct usb_interface *interface = to_usb_interface(dev);
	struct usb_line6_pod *pod = usb_get_intfdata(interface);

	int size = 3 + sizeof(pod->prog_data_buf);
	char *sysex = pod_alloc_sysex_buffer(pod, POD_SYSEX_STORE, size);
	if (!sysex)
		return 0;

	sysex[SYSEX_DATA_OFS] = 5;  /* see pod_dump() */
	pod_resolve(buf, block0, block1, sysex + SYSEX_DATA_OFS + 1);
	memcpy(sysex + SYSEX_DATA_OFS + 3, &pod->prog_data_buf, sizeof(pod->prog_data_buf));

	line6_send_sysex_message(&pod->line6, sysex, size);
	kfree(sysex);
	/* needs some delay here on AMD64 platform */
	return count;
}