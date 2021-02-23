#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int pending_idx; int /*<<< orphan*/  lock; int /*<<< orphan*/  cv; int /*<<< orphan*/  efd; int /*<<< orphan*/  cb_cookie; int /*<<< orphan*/  (* release_cb ) (int /*<<< orphan*/ ,int) ;} ;
typedef  TYPE_1__ TBuffer ;

/* Variables and functions */
 int /*<<< orphan*/  efd_write (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_cond_signal (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int) ; 

void tbuffer_dispatch(TBuffer *tb, int idx) {
  pthread_mutex_lock(&tb->lock);

  if (tb->pending_idx != -1) {
    //printf("tbuffer (%s) dropped!\n", tb->name ? tb->name : "?");
    if (tb->release_cb) {
      tb->release_cb(tb->cb_cookie, tb->pending_idx);
    }
    tb->pending_idx = -1;
  }

  tb->pending_idx = idx;

  efd_write(tb->efd);
  pthread_cond_signal(&tb->cv);

  pthread_mutex_unlock(&tb->lock);  
}