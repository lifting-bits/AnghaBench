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
struct ptunit_result {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pt_free_encoder (int /*<<< orphan*/ *) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result free_encoder_null(void)
{
	pt_free_encoder(NULL);

	return ptu_passed();
}