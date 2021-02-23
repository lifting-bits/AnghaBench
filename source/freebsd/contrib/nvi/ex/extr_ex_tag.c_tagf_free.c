#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  tagfq; } ;
struct TYPE_7__ {struct TYPE_7__* name; } ;
typedef  TYPE_1__ TAGF ;
typedef  int /*<<< orphan*/  SCR ;
typedef  TYPE_2__ EX_PRIVATE ;

/* Variables and functions */
 TYPE_2__* EXP (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TAILQ_REMOVE (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  q ; 

__attribute__((used)) static int
tagf_free(SCR *sp, TAGF *tfp)
{
	EX_PRIVATE *exp;

	exp = EXP(sp);
	TAILQ_REMOVE(exp->tagfq, tfp, q);
	free(tfp->name);
	free(tfp);
	return (0);
}