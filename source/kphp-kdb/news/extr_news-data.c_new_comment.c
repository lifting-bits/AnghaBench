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
typedef  int /*<<< orphan*/  comment_t ;

/* Variables and functions */
 int /*<<< orphan*/  COMM_MODE ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  comments_kept ; 
 int /*<<< orphan*/ * zmalloc0 (int) ; 

__attribute__((used)) static comment_t *new_comment (void) {
  assert (COMM_MODE);
  comments_kept++;
  return zmalloc0 (sizeof (comment_t));
}