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
struct mp_log {int dummy; } ;

/* Variables and functions */
 int mp_set_avopts_pos (struct mp_log*,void*,void*,char**) ; 

int mp_set_avopts(struct mp_log *log, void *avobj, char **kv)
{
    return mp_set_avopts_pos(log, avobj, avobj, kv);
}