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
typedef  int /*<<< orphan*/  tree ;
typedef  int /*<<< orphan*/  bitmap_set_t ;

/* Variables and functions */
 int /*<<< orphan*/  bitmap_insert_into_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ bitmap_set_contains_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bitmap_set_replace_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_value_handle (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bitmap_value_replace_in_set (bitmap_set_t set, tree expr)
{
  tree val = get_value_handle (expr);
  if (bitmap_set_contains_value (set, val))
    bitmap_set_replace_value (set, val, expr);
  else
    bitmap_insert_into_set (set, expr);
}