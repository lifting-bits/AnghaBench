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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  R600_GICST_DFLT ; 
 int /*<<< orphan*/  r600_set_git (struct radeon_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rv6xx_program_git(struct radeon_device *rdev)
{
	r600_set_git(rdev, R600_GICST_DFLT);
}