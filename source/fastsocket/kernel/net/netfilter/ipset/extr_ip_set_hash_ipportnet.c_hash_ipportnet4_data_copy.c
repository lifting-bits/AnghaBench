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
struct hash_ipportnet4_elem {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (struct hash_ipportnet4_elem*,struct hash_ipportnet4_elem const*,int) ; 

__attribute__((used)) static inline void
hash_ipportnet4_data_copy(struct hash_ipportnet4_elem *dst,
			  const struct hash_ipportnet4_elem *src)
{
	memcpy(dst, src, sizeof(*dst));
}