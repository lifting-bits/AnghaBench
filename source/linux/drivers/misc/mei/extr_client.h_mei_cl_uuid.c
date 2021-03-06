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
typedef  int /*<<< orphan*/  uuid_le ;
struct mei_cl {int /*<<< orphan*/  me_cl; } ;

/* Variables and functions */
 int /*<<< orphan*/  const* mei_me_cl_uuid (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline const uuid_le *mei_cl_uuid(const struct mei_cl *cl)
{
	return mei_me_cl_uuid(cl->me_cl);
}