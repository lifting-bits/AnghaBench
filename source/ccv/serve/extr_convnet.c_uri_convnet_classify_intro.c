#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
typedef  TYPE_2__ ebb_buf ;
struct TYPE_5__ {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
struct TYPE_7__ {TYPE_1__ desc; } ;
typedef  TYPE_3__ convnet_context_t ;

/* Variables and functions */

int uri_convnet_classify_intro(const void* context, const void* parsed, ebb_buf* buf)
{
	convnet_context_t* convnet_context = (convnet_context_t*)context;
	buf->data = convnet_context->desc.data;
	buf->len = convnet_context->desc.len;
	return 0;
}