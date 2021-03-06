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
struct crypto_alg {int /*<<< orphan*/  cra_name; int /*<<< orphan*/  cra_driver_name; } ;

/* Variables and functions */
 int crypto_unregister_alg (struct crypto_alg*) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

int crypto_unregister_algs(struct crypto_alg *algs, int count)
{
	int i, ret;

	for (i = 0; i < count; i++) {
		ret = crypto_unregister_alg(&algs[i]);
		if (ret)
			pr_err("Failed to unregister %s %s: %d\n",
			       algs[i].cra_driver_name, algs[i].cra_name, ret);
	}

	return 0;
}