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
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,scalar_t__) ; 

__attribute__((used)) static int stdifunion(void *p, const char *k, const char *v) {
	return !strncmp (v, "union", strlen ("union") + 1);
}