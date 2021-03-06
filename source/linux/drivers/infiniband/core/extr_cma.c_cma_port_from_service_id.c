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
typedef  int /*<<< orphan*/  u16 ;
typedef  int /*<<< orphan*/  __be64 ;

/* Variables and functions */
 int /*<<< orphan*/  be64_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u16 cma_port_from_service_id(__be64 service_id)
{
	return (u16)be64_to_cpu(service_id);
}