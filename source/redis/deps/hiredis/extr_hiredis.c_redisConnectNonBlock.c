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
struct TYPE_4__ {int /*<<< orphan*/  options; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ redisOptions ;
typedef  int /*<<< orphan*/  redisContext ;

/* Variables and functions */
 int /*<<< orphan*/  REDIS_OPTIONS_SET_TCP (TYPE_1__*,char const*,int) ; 
 int /*<<< orphan*/  REDIS_OPT_NONBLOCK ; 
 int /*<<< orphan*/ * redisConnectWithOptions (TYPE_1__*) ; 

redisContext *redisConnectNonBlock(const char *ip, int port) {
    redisOptions options = {0};
    REDIS_OPTIONS_SET_TCP(&options, ip, port);
    options.options |= REDIS_OPT_NONBLOCK;
    return redisConnectWithOptions(&options);
}