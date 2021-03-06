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
typedef  int /*<<< orphan*/  json_t ;

/* Variables and functions */
 scalar_t__ json_integer_value (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int json_integer_equal(json_t *integer1, json_t *integer2)
{
    return json_integer_value(integer1) == json_integer_value(integer2);
}