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
 int /*<<< orphan*/  gdb_kod_request (char*,int) ; 
 int /*<<< orphan*/  stub1 (char*,int) ; 

__attribute__((used)) static void
info_kod_command (char *arg, int from_tty)
{
  (*gdb_kod_request) (arg, from_tty);
}