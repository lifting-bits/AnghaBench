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

/* Variables and functions */
 int /*<<< orphan*/  LEV_FR_DELALL_REQ ; 
 int /*<<< orphan*/  alloc_log_event (int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ conv_uid (int) ; 
 int delete_all_friend_requests (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_user (int) ; 

int do_delete_all_friend_requests (int user_id) {

  if (conv_uid (user_id) < 0) {
    return -1;
  }

  alloc_log_event (LEV_FR_DELALL_REQ, 8, user_id);

  return delete_all_friend_requests (get_user (user_id));
}