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
struct Range {scalar_t__ begin; } ;

/* Variables and functions */

__attribute__((used)) static int
range_compare(const void *lhs, const void *rhs)
{
    struct Range *left = (struct Range *)lhs;
    struct Range *right = (struct Range *)rhs;

    if (left->begin < right->begin)
        return -1;
    else if (left->begin > right->begin)
        return 1;
    else
        return 0;
}