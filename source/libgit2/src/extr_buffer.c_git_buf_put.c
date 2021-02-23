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
struct TYPE_4__ {size_t size; char* ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 int /*<<< orphan*/  ENSURE_SIZE (TYPE_1__*,size_t) ; 
 int /*<<< orphan*/  GIT_ERROR_CHECK_ALLOC_ADD (size_t*,size_t,int) ; 
 int /*<<< orphan*/  assert (char const*) ; 
 int /*<<< orphan*/  memmove (char*,char const*,size_t) ; 

int git_buf_put(git_buf *buf, const char *data, size_t len)
{
	if (len) {
		size_t new_size;

		assert(data);

		GIT_ERROR_CHECK_ALLOC_ADD(&new_size, buf->size, len);
		GIT_ERROR_CHECK_ALLOC_ADD(&new_size, new_size, 1);
		ENSURE_SIZE(buf, new_size);
		memmove(buf->ptr + buf->size, data, len);
		buf->size += len;
		buf->ptr[buf->size] = '\0';
	}
	return 0;
}