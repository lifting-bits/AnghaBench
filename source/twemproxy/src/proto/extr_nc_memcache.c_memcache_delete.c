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
struct msg {scalar_t__ type; } ;

/* Variables and functions */
 scalar_t__ MSG_REQ_MC_DELETE ; 

__attribute__((used)) static bool
memcache_delete(struct msg *r)
{
    if (r->type == MSG_REQ_MC_DELETE) {
        return true;
    }

    return false;
}