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
struct TYPE_3__ {size_t max_len; size_t len; } ;
typedef  TYPE_1__ RAND_POOL ;

/* Variables and functions */

size_t rand_pool_bytes_remaining(RAND_POOL *pool)
{
    return pool->max_len - pool->len;
}