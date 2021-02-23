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
typedef  int /*<<< orphan*/  Tox ;

/* Variables and functions */
 int MIN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tox_iterate (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tox_iteration_interval (int /*<<< orphan*/ *) ; 

int iterate_tox(Tox *bootstrap, Tox *Alice, Tox *Bob)
{
    tox_iterate(bootstrap);
    tox_iterate(Alice);
    tox_iterate(Bob);

    return MIN(tox_iteration_interval(Alice), tox_iteration_interval(Bob));
}