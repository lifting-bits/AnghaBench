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
struct vmw_buffer_object {int /*<<< orphan*/  base; } ;

/* Variables and functions */
 int /*<<< orphan*/  ttm_bo_put (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void vmw_bo_unreference(struct vmw_buffer_object **buf)
{
	struct vmw_buffer_object *tmp_buf = *buf;

	*buf = NULL;
	if (tmp_buf != NULL) {
		ttm_bo_put(&tmp_buf->base);
	}
}