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
struct winlink {int flags; } ;

/* Variables and functions */
 int WINLINK_ALERTFLAGS ; 
 struct winlink* winlink_previous (struct winlink*) ; 

__attribute__((used)) static struct winlink *
session_previous_alert(struct winlink *wl)
{
	while (wl != NULL) {
		if (wl->flags & WINLINK_ALERTFLAGS)
			break;
		wl = winlink_previous(wl);
	}
	return (wl);
}