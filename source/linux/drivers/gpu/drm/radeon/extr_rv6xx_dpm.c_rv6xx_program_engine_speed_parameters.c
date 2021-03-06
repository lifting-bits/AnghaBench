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
 int /*<<< orphan*/  R600_SPLLSTEPUNIT_DFLT ; 
 int /*<<< orphan*/  r600_vid_rt_set_ssu (struct radeon_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rv6xx_enable_engine_feedback_and_reference_sync (struct radeon_device*) ; 

__attribute__((used)) static void rv6xx_program_engine_speed_parameters(struct radeon_device *rdev)
{
	r600_vid_rt_set_ssu(rdev, R600_SPLLSTEPUNIT_DFLT);
	rv6xx_enable_engine_feedback_and_reference_sync(rdev);
}