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
typedef  int /*<<< orphan*/  REgg ;

/* Variables and functions */
 int /*<<< orphan*/  r_egg_printf (int /*<<< orphan*/ *,char*,char const*,char const*) ; 

__attribute__((used)) static void emit_equ (REgg *egg, const char *key, const char *value) {
	r_egg_printf (egg, "equ (%s, %s)\n", key, value);
}