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
struct extent_buffer {int dummy; } ;

/* Variables and functions */
 scalar_t__ btrfs_header_level (struct extent_buffer const*) ; 

__attribute__((used)) static inline int btrfs_is_leaf(const struct extent_buffer *eb)
{
	return btrfs_header_level(eb) == 0;
}