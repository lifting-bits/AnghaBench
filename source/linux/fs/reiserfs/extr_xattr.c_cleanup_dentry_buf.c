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
struct reiserfs_dentry_buf {int count; scalar_t__* dentries; } ;

/* Variables and functions */
 int /*<<< orphan*/  dput (scalar_t__) ; 

__attribute__((used)) static void
cleanup_dentry_buf(struct reiserfs_dentry_buf *buf)
{
	int i;

	for (i = 0; i < buf->count; i++)
		if (buf->dentries[i])
			dput(buf->dentries[i]);
}