#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct seq_file {int /*<<< orphan*/  private; } ;
struct inode {int dummy; } ;
struct file {struct seq_file* private_data; } ;
struct TYPE_2__ {int /*<<< orphan*/  data; } ;

/* Variables and functions */
 TYPE_1__* PDE (struct inode*) ; 
 int /*<<< orphan*/  afs_proc_cells_ops ; 
 int seq_open (struct file*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int afs_proc_cells_open(struct inode *inode, struct file *file)
{
	struct seq_file *m;
	int ret;

	ret = seq_open(file, &afs_proc_cells_ops);
	if (ret < 0)
		return ret;

	m = file->private_data;
	m->private = PDE(inode)->data;

	return 0;
}