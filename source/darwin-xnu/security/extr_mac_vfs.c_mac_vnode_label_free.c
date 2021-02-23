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
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct label*) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int /*<<< orphan*/  vnode_label_destroy ; 

void
mac_vnode_label_free(struct label *label)
{
	MAC_PERFORM(vnode_label_destroy, label);
	mac_labelzone_free(label);
}