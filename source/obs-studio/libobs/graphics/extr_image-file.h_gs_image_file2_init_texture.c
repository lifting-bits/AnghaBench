#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  image; } ;
typedef  TYPE_1__ gs_image_file2_t ;

/* Variables and functions */
 int /*<<< orphan*/  gs_image_file_init_texture (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void gs_image_file2_init_texture(gs_image_file2_t *if2)
{
	gs_image_file_init_texture(&if2->image);
}