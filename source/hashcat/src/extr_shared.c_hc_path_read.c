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
 int /*<<< orphan*/  R_OK ; 
 int access (char const*,int /*<<< orphan*/ ) ; 

bool hc_path_read (const char *path)
{
  if (access (path, R_OK) == -1) return false;

  return true;
}