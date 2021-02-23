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
typedef  int /*<<< orphan*/  tox_self_connection_status_cb ;
typedef  int /*<<< orphan*/  Tox ;
typedef  int /*<<< orphan*/  Messenger ;

/* Variables and functions */
 int /*<<< orphan*/  m_callback_core_connection (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void*) ; 

void tox_callback_self_connection_status(Tox *tox, tox_self_connection_status_cb *function, void *user_data)
{
    Messenger *m = tox;
    m_callback_core_connection(m, function, user_data);
}