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

/* Variables and functions */
 int /*<<< orphan*/  DOUBLE_SHORTEST_DECIMAL_LEN ; 
 int /*<<< orphan*/  double_to_shortest_decimal_buf (double,char* const) ; 
 scalar_t__ palloc (int /*<<< orphan*/ ) ; 

char *
double_to_shortest_decimal(double f)
{
	char	   *const result = (char *) palloc(DOUBLE_SHORTEST_DECIMAL_LEN);

	double_to_shortest_decimal_buf(f, result);
	return result;
}