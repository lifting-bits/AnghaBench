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
struct lev_photo_del_photo_location {int user_id; int photo_id; } ;

/* Variables and functions */
 scalar_t__ LEV_PHOTO_DEL_PHOTO_LOCATION ; 
 int MY_LOG_EVENT_HANDLER (int /*<<< orphan*/ ,int) ; 
 struct lev_photo_del_photo_location* alloc_log_event (scalar_t__,int,int) ; 
 int /*<<< orphan*/  del_photo_location ; 
 int mode ; 

int do_del_photo_location (int uid, int pid, int original) {
  if (original < 0 || original > 1) {
    return 0;
  }

  int size = sizeof (struct lev_photo_del_photo_location);
  struct lev_photo_del_photo_location *E = alloc_log_event (LEV_PHOTO_DEL_PHOTO_LOCATION + (mode << 16) + (original << 10), size, uid);

  E->user_id = uid;
  E->photo_id = pid;

  return MY_LOG_EVENT_HANDLER (del_photo_location, 1);
}