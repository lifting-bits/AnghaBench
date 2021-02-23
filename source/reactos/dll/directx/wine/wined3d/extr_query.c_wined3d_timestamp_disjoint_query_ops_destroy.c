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
struct wined3d_query {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  heap_free (struct wined3d_query*) ; 

__attribute__((used)) static void wined3d_timestamp_disjoint_query_ops_destroy(struct wined3d_query *query)
{
    heap_free(query);
}