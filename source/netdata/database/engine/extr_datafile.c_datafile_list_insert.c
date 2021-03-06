#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {struct rrdengine_datafile* last; struct rrdengine_datafile* first; } ;
struct rrdengine_instance {TYPE_1__ datafiles; } ;
struct rrdengine_datafile {struct rrdengine_datafile* next; } ;

/* Variables and functions */
 scalar_t__ likely (int) ; 
 scalar_t__ unlikely (int) ; 

void datafile_list_insert(struct rrdengine_instance *ctx, struct rrdengine_datafile *datafile)
{
    if (likely(NULL != ctx->datafiles.last)) {
        ctx->datafiles.last->next = datafile;
    }
    if (unlikely(NULL == ctx->datafiles.first)) {
        ctx->datafiles.first = datafile;
    }
    ctx->datafiles.last = datafile;
}