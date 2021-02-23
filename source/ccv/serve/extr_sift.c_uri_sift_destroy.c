#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_2__* data; } ;
struct TYPE_5__ {TYPE_1__ desc; } ;
typedef  TYPE_2__ sift_context_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_2__*) ; 

void uri_sift_destroy(void* context)
{
	sift_context_t* sift_context = (sift_context_t*)context;
	free(sift_context->desc.data);
	free(sift_context);
}