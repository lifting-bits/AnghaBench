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
struct ion_handle_data {int /*<<< orphan*/  handle; } ;
struct TYPE_3__ {int /*<<< orphan*/  handle; } ;
typedef  TYPE_1__ VisionBuf ;

/* Variables and functions */
 int /*<<< orphan*/  ION_IOC_FREE ; 
 int /*<<< orphan*/  assert (int) ; 
 int ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ion_handle_data*) ; 
 int /*<<< orphan*/  ion_fd ; 

void visionbuf_free(const VisionBuf* buf) {
  struct ion_handle_data handle_data = {
    .handle = buf->handle,
  };
  int ret = ioctl(ion_fd, ION_IOC_FREE, &handle_data);
  assert(ret == 0);
}