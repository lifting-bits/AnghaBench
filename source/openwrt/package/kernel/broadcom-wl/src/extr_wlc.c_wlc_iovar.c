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
typedef  int wlc_param ;

/* Variables and functions */
 int GET ; 
#define  INT 129 
#define  MAC 128 
 int PARAM_TYPE ; 
 int SET ; 
 int /*<<< orphan*/  interface ; 
 int wl_iovar_get (int /*<<< orphan*/ ,char*,void*,int) ; 
 int wl_iovar_set (int /*<<< orphan*/ ,char*,void*,int) ; 
 int wl_iovar_setint (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int wlc_iovar(wlc_param param, void *data, void *value)
{
	int *val = (int *) value;
	char *iov = *((char **) data);
	int ret = 0;
	
	if (param & SET) {
		switch(param & PARAM_TYPE) {
			case INT:
				ret = wl_iovar_setint(interface, iov, *val);
				break;
			case MAC:
				ret = wl_iovar_set(interface, iov, value, 6);
				break;
		}
	}
	if (param & GET) {
		switch(param & PARAM_TYPE) {
			case INT:
				ret = wl_iovar_get(interface, iov, val, sizeof(int));
				break;
			case MAC:
				ret = wl_iovar_get(interface, iov, value, 6);
				break;
		}
	}

	return ret;
}