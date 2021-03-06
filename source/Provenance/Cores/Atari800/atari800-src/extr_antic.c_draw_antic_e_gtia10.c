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
typedef  int /*<<< orphan*/  UWORD ;
typedef  int /*<<< orphan*/  ULONG ;
typedef  int /*<<< orphan*/  UBYTE ;

/* Variables and functions */
 int /*<<< orphan*/  draw_an_gtia10 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  prepare_an_antic_e (int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static void draw_antic_e_gtia10 (int nchars, const UBYTE *antic_memptr, UWORD *ptr, const ULONG *t_pm_scanline_ptr)
{
	prepare_an_antic_e(nchars, antic_memptr, t_pm_scanline_ptr);
	draw_an_gtia10(t_pm_scanline_ptr);
}