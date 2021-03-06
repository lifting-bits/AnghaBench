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
struct mtx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MA_OWNED ; 
 int /*<<< orphan*/  mtx_assert (struct mtx*,int /*<<< orphan*/ ) ; 

void
snd_mtxassert(void *m)
{
#ifdef INVARIANTS
	struct mtx *mtx = m;

	mtx_assert(mtx, MA_OWNED);
#endif
}