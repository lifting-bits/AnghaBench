#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  int int64_t ;
typedef  int /*<<< orphan*/  id ;
struct TYPE_7__ {scalar_t__ module; } ;
struct TYPE_6__ {scalar_t__ module; void* data; } ;
typedef  int /*<<< orphan*/  RedisModuleTimerID ;
typedef  TYPE_1__ RedisModuleTimer ;
typedef  TYPE_2__ RedisModuleCtx ;

/* Variables and functions */
 int REDISMODULE_ERR ; 
 int REDISMODULE_OK ; 
 int /*<<< orphan*/  Timers ; 
 int ntohu64 (int /*<<< orphan*/ ) ; 
 TYPE_1__* raxFind (int /*<<< orphan*/ ,unsigned char*,int) ; 
 TYPE_1__* raxNotFound ; 
 int ustime () ; 

int RM_GetTimerInfo(RedisModuleCtx *ctx, RedisModuleTimerID id, uint64_t *remaining, void **data) {
    RedisModuleTimer *timer = raxFind(Timers,(unsigned char*)&id,sizeof(id));
    if (timer == raxNotFound || timer->module != ctx->module)
        return REDISMODULE_ERR;
    if (remaining) {
        int64_t rem = ntohu64(id)-ustime();
        if (rem < 0) rem = 0;
        *remaining = rem/1000; /* Scale to milliseconds. */
    }
    if (data) *data = timer->data;
    return REDISMODULE_OK;
}