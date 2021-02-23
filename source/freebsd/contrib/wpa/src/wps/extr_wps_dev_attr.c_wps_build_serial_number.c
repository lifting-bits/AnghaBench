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
struct wps_device_data {scalar_t__ serial_number; } ;
struct wpabuf {int dummy; } ;

/* Variables and functions */
 size_t ATTR_SERIAL_NUMBER ; 
 int /*<<< orphan*/  MSG_DEBUG ; 
 size_t os_strlen (scalar_t__) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  wpabuf_put_be16 (struct wpabuf*,size_t) ; 
 int /*<<< orphan*/  wpabuf_put_data (struct wpabuf*,scalar_t__,size_t) ; 
 int /*<<< orphan*/  wpabuf_put_u8 (struct wpabuf*,char) ; 

int wps_build_serial_number(struct wps_device_data *dev, struct wpabuf *msg)
{
	size_t len;
	wpa_printf(MSG_DEBUG, "WPS:  * Serial Number");
	wpabuf_put_be16(msg, ATTR_SERIAL_NUMBER);
	len = dev->serial_number ? os_strlen(dev->serial_number) : 0;
#ifndef CONFIG_WPS_STRICT
	if (len == 0) {
		/*
		 * Some deployed WPS implementations fail to parse zero-length
		 * attributes. As a workaround, send a space character if the
		 * device attribute string is empty.
		 */
		wpabuf_put_be16(msg, 1);
		wpabuf_put_u8(msg, ' ');
		return 0;
	}
#endif /* CONFIG_WPS_STRICT */
	wpabuf_put_be16(msg, len);
	wpabuf_put_data(msg, dev->serial_number, len);
	return 0;
}