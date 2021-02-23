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
 int /*<<< orphan*/  MAC_POLICY_CHECK (int /*<<< orphan*/ ,struct label*,int) ; 
 int /*<<< orphan*/  MAC_POLICY_CHECK_NOSLEEP (int /*<<< orphan*/ ,struct label*,int) ; 
 int /*<<< orphan*/  MAC_POLICY_PERFORM_NOSLEEP (int /*<<< orphan*/ ,struct label*) ; 
 int M_WAITOK ; 
 struct label* mac_labelzone_alloc (int) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int /*<<< orphan*/  socket_destroy_label ; 
 int /*<<< orphan*/  socket_init_label ; 

struct label *
mac_socket_label_alloc(int flag)
{
	struct label *label;
	int error;

	label = mac_labelzone_alloc(flag);
	if (label == NULL)
		return (NULL);

	if (flag & M_WAITOK)
		MAC_POLICY_CHECK(socket_init_label, label, flag);
	else
		MAC_POLICY_CHECK_NOSLEEP(socket_init_label, label, flag);
	if (error) {
		MAC_POLICY_PERFORM_NOSLEEP(socket_destroy_label, label);
		mac_labelzone_free(label);
		return (NULL);
	}
	return (label);
}