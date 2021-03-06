#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {float** m; } ;
typedef  TYPE_1__ VG_MAT3X3_T ;

/* Variables and functions */
 int /*<<< orphan*/  vcos_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vg_mat3x3_is_affine_or_nans (TYPE_1__ const*) ; 

float vg_mat3x3_affine_det(const VG_MAT3X3_T *a)
{
   vcos_assert(vg_mat3x3_is_affine_or_nans(a));
   return (a->m[0][0] * a->m[1][1]) - (a->m[1][0] * a->m[0][1]);
}