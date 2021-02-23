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
typedef  int /*<<< orphan*/  ngx_cycle_t ;

/* Variables and functions */
 int /*<<< orphan*/ * event_index ; 
 int /*<<< orphan*/ * event_list ; 
 int /*<<< orphan*/  ngx_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ngx_poll_done(ngx_cycle_t *cycle)
{
    ngx_free(event_list);
    ngx_free(event_index);

    event_list = NULL;
    event_index = NULL;
}