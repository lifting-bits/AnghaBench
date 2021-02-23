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
struct stat {int dummy; } ;
struct fuse_file_info {int /*<<< orphan*/  fh; } ;

/* Variables and functions */
 int errno ; 
 int fstat (int /*<<< orphan*/ ,struct stat*) ; 

__attribute__((used)) static int pifs_fgetattr(const char *path, struct stat *buf,
                        struct fuse_file_info *info)
{
  int ret = fstat(info->fh, buf);
  return ret == -1 ? -errno : ret;
}