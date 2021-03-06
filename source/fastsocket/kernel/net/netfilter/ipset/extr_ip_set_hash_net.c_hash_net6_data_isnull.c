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
struct hash_net6_elem {scalar_t__ cidr; } ;

/* Variables and functions */

__attribute__((used)) static inline bool
hash_net6_data_isnull(const struct hash_net6_elem *elem)
{
	return elem->cidr == 0;
}