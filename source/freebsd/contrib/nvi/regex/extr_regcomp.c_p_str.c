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
struct parse {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GETNEXT () ; 
 scalar_t__ MORE () ; 
 int /*<<< orphan*/  REG_EMPTY ; 
 int /*<<< orphan*/  REQUIRE (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ordinary (struct parse*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
p_str(struct parse *p)
{
	(void)REQUIRE(MORE(), REG_EMPTY);
	while (MORE())
		ordinary(p, GETNEXT());
}