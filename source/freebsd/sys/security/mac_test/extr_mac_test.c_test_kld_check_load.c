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
struct vnode {int dummy; } ;
struct ucred {struct label* cr_label; } ;
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  COUNTER_INC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LABEL_CHECK (struct label*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAGIC_CRED ; 
 int /*<<< orphan*/  MAGIC_VNODE ; 
 int /*<<< orphan*/  kld_check_load ; 

__attribute__((used)) static int
test_kld_check_load(struct ucred *cred, struct vnode *vp,
    struct label *label)
{

	LABEL_CHECK(cred->cr_label, MAGIC_CRED);
	LABEL_CHECK(label, MAGIC_VNODE);
	COUNTER_INC(kld_check_load);

	return (0);
}