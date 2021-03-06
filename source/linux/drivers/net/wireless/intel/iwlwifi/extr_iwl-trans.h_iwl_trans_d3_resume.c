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
struct iwl_trans {TYPE_1__* ops; } ;
typedef  enum iwl_d3_status { ____Placeholder_iwl_d3_status } iwl_d3_status ;
struct TYPE_2__ {int (* d3_resume ) (struct iwl_trans*,int*,int,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  might_sleep () ; 
 int stub1 (struct iwl_trans*,int*,int,int) ; 

__attribute__((used)) static inline int iwl_trans_d3_resume(struct iwl_trans *trans,
				      enum iwl_d3_status *status,
				      bool test, bool reset)
{
	might_sleep();
	if (!trans->ops->d3_resume)
		return 0;

	return trans->ops->d3_resume(trans, status, test, reset);
}