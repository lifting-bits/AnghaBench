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
struct metapage {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __lock_metapage (struct metapage*) ; 
 scalar_t__ trylock_metapage (struct metapage*) ; 

__attribute__((used)) static inline void lock_metapage(struct metapage *mp)
{
	if (trylock_metapage(mp))
		__lock_metapage(mp);
}