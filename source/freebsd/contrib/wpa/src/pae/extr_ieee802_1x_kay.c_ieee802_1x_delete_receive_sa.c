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
struct receive_sa {int dummy; } ;
struct ieee802_1x_kay {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ieee802_1x_kay_deinit_receive_sa (struct receive_sa*) ; 
 int /*<<< orphan*/  secy_delete_receive_sa (struct ieee802_1x_kay*,struct receive_sa*) ; 
 int /*<<< orphan*/  secy_disable_receive_sa (struct ieee802_1x_kay*,struct receive_sa*) ; 

__attribute__((used)) static void ieee802_1x_delete_receive_sa(struct ieee802_1x_kay *kay,
					 struct receive_sa *sa)
{
	secy_disable_receive_sa(kay, sa);
	secy_delete_receive_sa(kay, sa);
	ieee802_1x_kay_deinit_receive_sa(sa);
}