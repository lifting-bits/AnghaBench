#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ request_method; } ;

/* Variables and functions */
 TYPE_1__ SG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  request_info ; 

char *fpm_php_request_method(void) /* {{{ */
{
	return (char *) SG(request_info).request_method;
}