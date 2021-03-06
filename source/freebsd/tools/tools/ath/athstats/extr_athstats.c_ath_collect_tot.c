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
struct bsdstat {int dummy; } ;
struct athstatfoo_p {int /*<<< orphan*/  total; } ;

/* Variables and functions */
 int /*<<< orphan*/  ath_collect (struct athstatfoo_p*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ath_collect_tot(struct bsdstat *sf)
{
	struct athstatfoo_p *wf = (struct athstatfoo_p *) sf;

	ath_collect(wf, &wf->total);
}