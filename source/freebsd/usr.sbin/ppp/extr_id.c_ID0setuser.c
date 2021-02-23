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
 int /*<<< orphan*/  AbortProgram (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EX_NOPERM ; 
 int /*<<< orphan*/  LogERROR ; 
 int /*<<< orphan*/  log_Printf (int /*<<< orphan*/ ,char*) ; 
 int seteuid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uid ; 

__attribute__((used)) static void
ID0setuser(void)
{
  if (seteuid(uid) == -1) {
    log_Printf(LogERROR, "ID0setuser: Unable to seteuid!\n");
    AbortProgram(EX_NOPERM);
  }
}