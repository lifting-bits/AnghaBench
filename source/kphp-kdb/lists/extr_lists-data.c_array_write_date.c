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
typedef  int /*<<< orphan*/  listree_t ;

/* Variables and functions */
 int /*<<< orphan*/  metafile_get_date (int) ; 
 int /*<<< orphan*/  writeout_int (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int array_write_date (listree_t *LT, int temp_id) {
  writeout_int (metafile_get_date (temp_id));
  return 0;
}