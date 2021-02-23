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
struct page {int dummy; } ;
struct inode {scalar_t__ i_nlink; void* i_ctime; int /*<<< orphan*/  i_mode; } ;
struct exofs_dir_entry {int dummy; } ;
struct dentry {struct inode* d_inode; } ;

/* Variables and functions */
 void* CURRENT_TIME ; 
 int EIO ; 
 int EMLINK ; 
 int ENOENT ; 
 int ENOTEMPTY ; 
 scalar_t__ EXOFS_LINK_MAX ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drop_nlink (struct inode*) ; 
 int exofs_add_link (struct dentry*,struct inode*) ; 
 int /*<<< orphan*/  exofs_delete_entry (struct exofs_dir_entry*,struct page*) ; 
 struct exofs_dir_entry* exofs_dotdot (struct inode*,struct page**) ; 
 int /*<<< orphan*/  exofs_empty_dir (struct inode*) ; 
 struct exofs_dir_entry* exofs_find_entry (struct inode*,struct dentry*,struct page**) ; 
 int exofs_set_link (struct inode*,struct exofs_dir_entry*,struct page*,struct inode*) ; 
 int /*<<< orphan*/  inode_dec_link_count (struct inode*) ; 
 int /*<<< orphan*/  inode_inc_link_count (struct inode*) ; 
 int /*<<< orphan*/  kunmap (struct page*) ; 
 int /*<<< orphan*/  page_cache_release (struct page*) ; 

__attribute__((used)) static int exofs_rename(struct inode *old_dir, struct dentry *old_dentry,
		struct inode *new_dir, struct dentry *new_dentry)
{
	struct inode *old_inode = old_dentry->d_inode;
	struct inode *new_inode = new_dentry->d_inode;
	struct page *dir_page = NULL;
	struct exofs_dir_entry *dir_de = NULL;
	struct page *old_page;
	struct exofs_dir_entry *old_de;
	int err = -ENOENT;

	old_de = exofs_find_entry(old_dir, old_dentry, &old_page);
	if (!old_de)
		goto out;

	if (S_ISDIR(old_inode->i_mode)) {
		err = -EIO;
		dir_de = exofs_dotdot(old_inode, &dir_page);
		if (!dir_de)
			goto out_old;
	}

	if (new_inode) {
		struct page *new_page;
		struct exofs_dir_entry *new_de;

		err = -ENOTEMPTY;
		if (dir_de && !exofs_empty_dir(new_inode))
			goto out_dir;

		err = -ENOENT;
		new_de = exofs_find_entry(new_dir, new_dentry, &new_page);
		if (!new_de)
			goto out_dir;
		inode_inc_link_count(old_inode);
		err = exofs_set_link(new_dir, new_de, new_page, old_inode);
		new_inode->i_ctime = CURRENT_TIME;
		if (dir_de)
			drop_nlink(new_inode);
		inode_dec_link_count(new_inode);
		if (err)
			goto out_dir;
	} else {
		if (dir_de) {
			err = -EMLINK;
			if (new_dir->i_nlink >= EXOFS_LINK_MAX)
				goto out_dir;
		}
		inode_inc_link_count(old_inode);
		err = exofs_add_link(new_dentry, old_inode);
		if (err) {
			inode_dec_link_count(old_inode);
			goto out_dir;
		}
		if (dir_de)
			inode_inc_link_count(new_dir);
	}

	old_inode->i_ctime = CURRENT_TIME;

	exofs_delete_entry(old_de, old_page);
	inode_dec_link_count(old_inode);

	if (dir_de) {
		err = exofs_set_link(old_inode, dir_de, dir_page, new_dir);
		inode_dec_link_count(old_dir);
		if (err)
			goto out_dir;
	}
	return 0;


out_dir:
	if (dir_de) {
		kunmap(dir_page);
		page_cache_release(dir_page);
	}
out_old:
	kunmap(old_page);
	page_cache_release(old_page);
out:
	return err;
}