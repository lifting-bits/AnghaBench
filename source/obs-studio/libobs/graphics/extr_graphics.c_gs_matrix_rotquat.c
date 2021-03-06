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
struct quat {int dummy; } ;
struct matrix4 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gs_valid (char*) ; 
 int /*<<< orphan*/  matrix4_rotate_i (struct matrix4*,struct quat const*,struct matrix4*) ; 
 int /*<<< orphan*/  thread_graphics ; 
 struct matrix4* top_matrix (int /*<<< orphan*/ ) ; 

void gs_matrix_rotquat(const struct quat *rot)
{
	struct matrix4 *top_mat;

	if (!gs_valid("gs_matrix_rotquat"))
		return;

	top_mat = top_matrix(thread_graphics);
	if (top_mat)
		matrix4_rotate_i(top_mat, rot, top_mat);
}