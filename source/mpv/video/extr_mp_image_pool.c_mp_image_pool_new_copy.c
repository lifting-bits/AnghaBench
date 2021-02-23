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
struct mp_image_pool {int dummy; } ;
struct mp_image {int /*<<< orphan*/  h; int /*<<< orphan*/  w; int /*<<< orphan*/  imgfmt; } ;

/* Variables and functions */
 int /*<<< orphan*/  mp_image_copy (struct mp_image*,struct mp_image*) ; 
 int /*<<< orphan*/  mp_image_copy_attributes (struct mp_image*,struct mp_image*) ; 
 struct mp_image* mp_image_pool_get (struct mp_image_pool*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

struct mp_image *mp_image_pool_new_copy(struct mp_image_pool *pool,
                                        struct mp_image *img)
{
    struct mp_image *new = mp_image_pool_get(pool, img->imgfmt, img->w, img->h);
    if (new) {
        mp_image_copy(new, img);
        mp_image_copy_attributes(new, img);
    }
    return new;
}