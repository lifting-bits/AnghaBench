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
typedef  int /*<<< orphan*/  ucl_object_t ;

/* Variables and functions */
 int /*<<< orphan*/  const* ucl_object_lookup_path_char (int /*<<< orphan*/  const*,char const*,char) ; 

const ucl_object_t *
ucl_object_lookup_path (const ucl_object_t *top, const char *path_in) {
	return ucl_object_lookup_path_char (top, path_in, '.');
}