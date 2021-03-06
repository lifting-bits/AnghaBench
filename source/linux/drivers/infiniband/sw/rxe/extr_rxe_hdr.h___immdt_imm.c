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
struct rxe_immdt {int /*<<< orphan*/  imm; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */

__attribute__((used)) static inline __be32 __immdt_imm(void *arg)
{
	struct rxe_immdt *immdt = arg;

	return immdt->imm;
}