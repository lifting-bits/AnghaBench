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
 int /*<<< orphan*/  arg_printusage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  getargs ; 
 int /*<<< orphan*/  num_args ; 

__attribute__((used)) static void
usage(int ecode)
{
    arg_printusage(getargs, num_args, NULL, "command [args...]");
    exit(ecode);
}