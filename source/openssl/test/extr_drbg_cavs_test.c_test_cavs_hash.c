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
 int /*<<< orphan*/  drbg_hash_test ; 
 int test_cavs_kats (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int test_cavs_hash(int i)
{
    return test_cavs_kats(drbg_hash_test, i);
}