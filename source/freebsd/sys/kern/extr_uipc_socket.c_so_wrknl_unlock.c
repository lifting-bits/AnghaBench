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
struct socket {int /*<<< orphan*/  so_snd; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOCKBUF_UNLOCK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SOCK_UNLOCK (struct socket*) ; 
 scalar_t__ SOLISTENING (struct socket*) ; 

__attribute__((used)) static void
so_wrknl_unlock(void *arg)
{
	struct socket *so = arg;

	if (SOLISTENING(so))
		SOCK_UNLOCK(so);
	else
		SOCKBUF_UNLOCK(&so->so_snd);
}