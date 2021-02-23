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
typedef  int /*<<< orphan*/  JsonVariant ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/ * JSON_VARIANT_MAGIC_NULL ; 
 int /*<<< orphan*/  assert_return (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

int json_variant_new_null(JsonVariant **ret) {
        assert_return(ret, -EINVAL);

        *ret = JSON_VARIANT_MAGIC_NULL;
        return 0;
}