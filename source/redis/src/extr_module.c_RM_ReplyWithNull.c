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
typedef  int /*<<< orphan*/  client ;
typedef  int /*<<< orphan*/  RedisModuleCtx ;

/* Variables and functions */
 int REDISMODULE_OK ; 
 int /*<<< orphan*/  addReplyNull (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * moduleGetReplyClient (int /*<<< orphan*/ *) ; 

int RM_ReplyWithNull(RedisModuleCtx *ctx) {
    client *c = moduleGetReplyClient(ctx);
    if (c == NULL) return REDISMODULE_OK;
    addReplyNull(c);
    return REDISMODULE_OK;
}