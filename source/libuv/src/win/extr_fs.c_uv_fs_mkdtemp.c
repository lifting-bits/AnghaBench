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
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_fs_t ;
typedef  int /*<<< orphan*/  uv_fs_cb ;

/* Variables and functions */
 int /*<<< orphan*/  INIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  POST ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UV_FS_MKDTEMP ; 
 int fs__capture_path (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int uv_translate_sys_error (int) ; 

int uv_fs_mkdtemp(uv_loop_t* loop, uv_fs_t* req, const char* tpl,
    uv_fs_cb cb) {
  int err;

  INIT(UV_FS_MKDTEMP);
  err = fs__capture_path(req, tpl, NULL, TRUE);
  if (err)
    return uv_translate_sys_error(err);

  POST;
}