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
typedef  int /*<<< orphan*/  zval ;
typedef  int /*<<< orphan*/  mysqli_object ;

/* Variables and functions */
 int /*<<< orphan*/  ZVAL_FALSE (int /*<<< orphan*/ *) ; 

__attribute__((used)) static zval *driver_embedded_read(mysqli_object *obj, zval *retval)
{
	ZVAL_FALSE(retval);
	return retval;
}