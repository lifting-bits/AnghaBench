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
typedef  int /*<<< orphan*/  token_t ;
struct sockaddr_in {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/ * au_to_sock_inet32 (struct sockaddr_in*) ; 

token_t *
au_to_sock_inet(struct sockaddr_in *so)
{

	return (au_to_sock_inet32(so));
}