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
struct TYPE_3__ {int* tree; } ;
typedef  TYPE_1__ KHRN_CACHE_T ;

/* Variables and functions */

__attribute__((used)) static int heap_avail(KHRN_CACHE_T *cache, int size)
{
   return cache->tree && cache->tree[1] >= size;
}