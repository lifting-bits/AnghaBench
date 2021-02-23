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
struct cryptocap {int cc_flags; } ;

/* Variables and functions */
 struct cryptocap* crypto_checkdriver (int) ; 

int
crypto_getcaps(int hid)
{
	struct cryptocap *cap = crypto_checkdriver(hid);
	return cap != NULL ? cap->cc_flags : 0;
}