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

/* Variables and functions */
 int /*<<< orphan*/  Z_PTR_P (int /*<<< orphan*/ *) ; 
 int phar_tar_writeheaders_int (int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static int phar_tar_writeheaders(zval *zv, void *argument) /* {{{ */
{
	return phar_tar_writeheaders_int(Z_PTR_P(zv), argument);
}