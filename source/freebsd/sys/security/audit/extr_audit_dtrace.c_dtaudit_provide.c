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
typedef  int /*<<< orphan*/  dtrace_probedesc_t ;

/* Variables and functions */
 int /*<<< orphan*/  au_evnamemap_foreach (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dtaudit_au_evnamemap_callback ; 

__attribute__((used)) static void
dtaudit_provide(void *arg, dtrace_probedesc_t *desc)
{

	/*
	 * Walk all registered number-to-name mapping entries, and ensure each
	 * is properly registered.
	 */
	au_evnamemap_foreach(dtaudit_au_evnamemap_callback);
}