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
struct TYPE_3__ {int /*<<< orphan*/  lines; int /*<<< orphan*/  pool; } ;
typedef  TYPE_1__ patch_image ;

/* Variables and functions */
 int /*<<< orphan*/  git_pool_clear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_vector_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void patch_image_free(patch_image *image)
{
	if (image == NULL)
		return;

	git_pool_clear(&image->pool);
	git_vector_free(&image->lines);
}