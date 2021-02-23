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
typedef  int /*<<< orphan*/  vfs_entry_t ;
struct _reent {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  off_t ;
typedef  int /*<<< orphan*/  __errno_r ;

/* Variables and functions */
 int /*<<< orphan*/  CHECK_AND_CALL (int,struct _reent*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int const,void const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EBADF ; 
 struct _reent* __getreent () ; 
 int get_local_fd (int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/ * get_vfs_for_fd (int) ; 
 int /*<<< orphan*/  pwrite ; 

ssize_t esp_vfs_pwrite(int fd, const void *src, size_t size, off_t offset)
{
    struct _reent *r = __getreent();
    const vfs_entry_t* vfs = get_vfs_for_fd(fd);
    const int local_fd = get_local_fd(vfs, fd);
    if (vfs == NULL || local_fd < 0) {
        __errno_r(r) = EBADF;
        return -1;
    }
    ssize_t ret;
    CHECK_AND_CALL(ret, r, vfs, pwrite, local_fd, src, size, offset);
    return ret;
}