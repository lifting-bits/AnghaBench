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
struct vpmtmr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_VPMTMR ; 
 int /*<<< orphan*/  free (struct vpmtmr*,int /*<<< orphan*/ ) ; 

void
vpmtmr_cleanup(struct vpmtmr *vpmtmr)
{

	free(vpmtmr, M_VPMTMR);
}