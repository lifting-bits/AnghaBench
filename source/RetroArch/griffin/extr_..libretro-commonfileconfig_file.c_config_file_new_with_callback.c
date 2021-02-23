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
typedef  int /*<<< orphan*/  config_file_t ;
typedef  int /*<<< orphan*/  config_file_cb_t ;

/* Variables and functions */
 int /*<<< orphan*/ * config_file_new_internal (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

config_file_t *config_file_new_with_callback(
      const char *path, config_file_cb_t *cb)
{
   return config_file_new_internal(path, 0, cb);
}