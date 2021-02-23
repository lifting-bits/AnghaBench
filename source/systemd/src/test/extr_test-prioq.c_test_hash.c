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
struct test {int /*<<< orphan*/  value; } ;
struct siphash {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  siphash24_compress (int /*<<< orphan*/ *,int,struct siphash*) ; 

__attribute__((used)) static void test_hash(const struct test *x, struct siphash *state) {
        siphash24_compress(&x->value, sizeof(x->value), state);
}