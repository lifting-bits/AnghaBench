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
 int /*<<< orphan*/  EVHTTP_REQ_LOCK ; 
 int /*<<< orphan*/  http_genmethod_test (void*,int /*<<< orphan*/ ,char*,char*) ; 

__attribute__((used)) static void
http_lock_test(void *arg)
{
	http_genmethod_test(arg, EVHTTP_REQ_LOCK, "LOCK", "/lockit");
}