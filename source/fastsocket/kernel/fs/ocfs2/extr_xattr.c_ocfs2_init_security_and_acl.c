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
struct ocfs2_security_xattr_info {int enable; int /*<<< orphan*/  value_len; int /*<<< orphan*/  value; int /*<<< orphan*/  name; } ;
struct inode {int dummy; } ;
struct buffer_head {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  XATTR_CREATE ; 
 int /*<<< orphan*/  brelse (struct buffer_head*) ; 
 int /*<<< orphan*/  mlog_errno (int) ; 
 int ocfs2_init_acl (int /*<<< orphan*/ *,struct inode*,struct inode*,int /*<<< orphan*/ *,struct buffer_head*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ocfs2_init_security_get (struct inode*,struct inode*,struct ocfs2_security_xattr_info*) ; 
 int ocfs2_inode_lock (struct inode*,struct buffer_head**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocfs2_inode_unlock (struct inode*,int /*<<< orphan*/ ) ; 
 int ocfs2_xattr_security_set (struct inode*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int ocfs2_init_security_and_acl(struct inode *dir,
				struct inode *inode)
{
	int ret = 0;
	struct buffer_head *dir_bh = NULL;
	struct ocfs2_security_xattr_info si = {
		.enable = 1,
	};

	ret = ocfs2_init_security_get(inode, dir, &si);
	if (!ret) {
		ret = ocfs2_xattr_security_set(inode, si.name,
					       si.value, si.value_len,
					       XATTR_CREATE);
		if (ret) {
			mlog_errno(ret);
			goto leave;
		}
	} else if (ret != -EOPNOTSUPP) {
		mlog_errno(ret);
		goto leave;
	}

	ret = ocfs2_inode_lock(dir, &dir_bh, 0);
	if (ret) {
		mlog_errno(ret);
		goto leave;
	}

	ret = ocfs2_init_acl(NULL, inode, dir, NULL, dir_bh, NULL, NULL);
	if (ret)
		mlog_errno(ret);

	ocfs2_inode_unlock(dir, 0);
	brelse(dir_bh);
leave:
	return ret;
}