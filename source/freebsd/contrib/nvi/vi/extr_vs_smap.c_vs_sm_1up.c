#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int rows; TYPE_1__* gp; } ;
struct TYPE_9__ {int /*<<< orphan*/  (* scr_move ) (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
typedef  int /*<<< orphan*/  SMAP ;
typedef  TYPE_2__ SCR ;

/* Variables and functions */
 scalar_t__ HMAP ; 
 scalar_t__ IS_ONELINE (TYPE_2__*) ; 
 scalar_t__ TMAP ; 
 int /*<<< orphan*/  memmove (scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ vs_deleteln (TYPE_2__*,int) ; 
 int vs_line (TYPE_2__*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ vs_sm_next (TYPE_2__*,scalar_t__,scalar_t__) ; 

int
vs_sm_1up(SCR *sp)
{
	/*
	 * Delete the top line of the screen.  Shift the screen map
	 * up and display a new line at the bottom of the screen.
	 */
	(void)sp->gp->scr_move(sp, 0, 0);
	if (vs_deleteln(sp, 1))
		return (1);

	/* One-line screens can fail. */
	if (IS_ONELINE(sp)) {
		if (vs_sm_next(sp, TMAP, TMAP))
			return (1);
	} else {
		memmove(HMAP, HMAP + 1, (sp->rows - 1) * sizeof(SMAP));
		if (vs_sm_next(sp, TMAP - 1, TMAP))
			return (1);
	}
	/* vs_sm_next() flushed the cache. */
	return (vs_line(sp, TMAP, NULL, NULL));
}