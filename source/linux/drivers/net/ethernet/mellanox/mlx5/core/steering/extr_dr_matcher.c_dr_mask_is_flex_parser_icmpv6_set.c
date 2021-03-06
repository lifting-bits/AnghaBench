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
struct mlx5dr_match_misc3 {scalar_t__ icmpv6_header_data; scalar_t__ icmpv6_code; scalar_t__ icmpv6_type; } ;

/* Variables and functions */

__attribute__((used)) static bool dr_mask_is_flex_parser_icmpv6_set(struct mlx5dr_match_misc3 *misc3)
{
	return (misc3->icmpv6_type || misc3->icmpv6_code ||
		misc3->icmpv6_header_data);
}