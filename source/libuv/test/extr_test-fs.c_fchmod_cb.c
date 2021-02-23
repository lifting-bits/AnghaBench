#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ fs_type; scalar_t__ result; scalar_t__ data; } ;
typedef  TYPE_1__ uv_fs_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ UV_FS_FCHMOD ; 
 int /*<<< orphan*/  check_permission (char*,int) ; 
 int /*<<< orphan*/  fchmod_cb_count ; 
 int /*<<< orphan*/  uv_fs_req_cleanup (TYPE_1__*) ; 

__attribute__((used)) static void fchmod_cb(uv_fs_t* req) {
  ASSERT(req->fs_type == UV_FS_FCHMOD);
  ASSERT(req->result == 0);
  fchmod_cb_count++;
  uv_fs_req_cleanup(req);
  check_permission("test_file", *(int*)req->data);
}