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
typedef  int /*<<< orphan*/  u_long ;
struct thread {int dummy; } ;
struct g_provider {int dummy; } ;

/* Variables and functions */
 int ENOIOCTL ; 

__attribute__((used)) static int
g_redboot_ioctl(struct g_provider *pp, u_long cmd, void *data, int fflag, struct thread *td)
{
	return (ENOIOCTL);
}