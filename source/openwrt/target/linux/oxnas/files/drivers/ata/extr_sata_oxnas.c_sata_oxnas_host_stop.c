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
struct ata_host {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTK (char*) ; 

__attribute__((used)) static void sata_oxnas_host_stop(struct ata_host *host_set)
{
	DPRINTK("\n");
}