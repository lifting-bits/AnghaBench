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
struct rmlock {int dummy; } ;
struct rm_priotracker {int dummy; } ;

/* Variables and functions */
 int _rm_rlock (struct rmlock*,struct rm_priotracker*,int) ; 

int
_rm_rlock_debug(struct rmlock *rm, struct rm_priotracker *tracker,
    int trylock, const char *file, int line)
{

	return _rm_rlock(rm, tracker, trylock);
}