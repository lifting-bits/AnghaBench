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
 int /*<<< orphan*/  BIO_meth_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * prefix_method ; 

void destroy_prefix_method(void)
{
    BIO_meth_free(prefix_method);
    prefix_method = NULL;
}