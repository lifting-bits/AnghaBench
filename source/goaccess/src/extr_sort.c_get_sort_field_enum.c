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
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FIELD ; 
 int str2enum (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 

int
get_sort_field_enum (const char *str)
{
  return str2enum (FIELD, ARRAY_SIZE (FIELD), str);
}