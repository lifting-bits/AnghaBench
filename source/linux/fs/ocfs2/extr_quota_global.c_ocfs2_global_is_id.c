#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ocfs2_mem_dqinfo {int /*<<< orphan*/  dqi_gi; } ;
struct ocfs2_global_disk_dqblk {int /*<<< orphan*/  dqb_id; } ;
struct TYPE_4__ {int /*<<< orphan*/  type; } ;
struct dquot {TYPE_2__ dq_id; int /*<<< orphan*/  dq_sb; } ;
struct TYPE_3__ {struct ocfs2_mem_dqinfo* dqi_priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  init_user_ns ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  make_kqid (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int qid_eq (int /*<<< orphan*/ ,TYPE_2__) ; 
 scalar_t__ qtree_entry_unused (int /*<<< orphan*/ *,void*) ; 
 TYPE_1__* sb_dqinfo (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ocfs2_global_is_id(void *dp, struct dquot *dquot)
{
	struct ocfs2_global_disk_dqblk *d = dp;
	struct ocfs2_mem_dqinfo *oinfo =
			sb_dqinfo(dquot->dq_sb, dquot->dq_id.type)->dqi_priv;

	if (qtree_entry_unused(&oinfo->dqi_gi, dp))
		return 0;

	return qid_eq(make_kqid(&init_user_ns, dquot->dq_id.type,
				le32_to_cpu(d->dqb_id)),
		      dquot->dq_id);
}