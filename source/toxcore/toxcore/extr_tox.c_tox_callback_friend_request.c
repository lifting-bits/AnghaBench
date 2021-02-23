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
typedef  int /*<<< orphan*/  tox_friend_request_cb ;
typedef  int /*<<< orphan*/  Tox ;
typedef  int /*<<< orphan*/  Messenger ;

/* Variables and functions */
 int /*<<< orphan*/  m_callback_friendrequest (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void*) ; 

void tox_callback_friend_request(Tox *tox, tox_friend_request_cb *function, void *user_data)
{
    Messenger *m = tox;
    m_callback_friendrequest(m, function, user_data);
}