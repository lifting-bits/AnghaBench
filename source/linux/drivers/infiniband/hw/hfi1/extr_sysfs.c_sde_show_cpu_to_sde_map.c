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
struct sdma_engine {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  sdma_get_cpu_to_sde_map (struct sdma_engine*,char*) ; 

__attribute__((used)) static ssize_t sde_show_cpu_to_sde_map(struct sdma_engine *sde, char *buf)
{
	return sdma_get_cpu_to_sde_map(sde, buf);
}