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
 int /*<<< orphan*/  BTRFS_WRITE_LOCK_BLOCKING ; 
 int /*<<< orphan*/  btrfs_clear_lock_blocking_rw (struct extent_buffer*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void btrfs_clear_lock_blocking(struct extent_buffer *eb)
{
	btrfs_clear_lock_blocking_rw(eb, BTRFS_WRITE_LOCK_BLOCKING);
}