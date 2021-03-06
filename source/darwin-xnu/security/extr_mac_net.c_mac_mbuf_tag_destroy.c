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
struct m_tag {int dummy; } ;
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct label*) ; 
 int /*<<< orphan*/  mac_label_destroy (struct label*) ; 
 int /*<<< orphan*/  mbuf_label_destroy ; 

void
mac_mbuf_tag_destroy(struct m_tag *tag)
{
	struct label *label;

	label = (struct label *)(tag + 1);
	MAC_PERFORM(mbuf_label_destroy, label);
	mac_label_destroy(label);

	return;
}