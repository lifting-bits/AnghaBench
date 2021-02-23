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
struct map_info {scalar_t__ map_priv_2; } ;
typedef  long ssize_t ;

/* Variables and functions */
 unsigned long WINDOW_LENGTH ; 
 unsigned long WINDOW_MASK ; 
 int /*<<< orphan*/  memcpy_toio (scalar_t__,void const*,unsigned long) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vmax301_page (struct map_info*,unsigned long) ; 
 int /*<<< orphan*/  vmax301_spin ; 

__attribute__((used)) static void vmax301_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
	while(len) {
		unsigned long thislen = len;
		if (len > (WINDOW_LENGTH - (to & WINDOW_MASK)))
			thislen = WINDOW_LENGTH-(to & WINDOW_MASK);

		spin_lock(&vmax301_spin);
		vmax301_page(map, to);
		memcpy_toio(map->map_priv_2 + to, from, thislen);
		spin_unlock(&vmax301_spin);
		to += thislen;
		from += thislen;
		len -= thislen;
	}
}