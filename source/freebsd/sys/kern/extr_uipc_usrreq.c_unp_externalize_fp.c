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
struct unpcb {int /*<<< orphan*/  unp_msgcount; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  UNP_LINK_WLOCK () ; 
 int /*<<< orphan*/  UNP_LINK_WUNLOCK () ; 
 struct unpcb* fptounp (struct file*) ; 
 int /*<<< orphan*/  unp_rights ; 

__attribute__((used)) static int
unp_externalize_fp(struct file *fp)
{
	struct unpcb *unp;
	int ret;

	UNP_LINK_WLOCK();
	if ((unp = fptounp(fp)) != NULL) {
		unp->unp_msgcount--;
		ret = 1;
	} else
		ret = 0;
	unp_rights--;
	UNP_LINK_WUNLOCK();
	return (ret);
}