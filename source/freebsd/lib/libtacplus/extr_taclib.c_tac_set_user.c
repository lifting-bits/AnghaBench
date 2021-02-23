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
struct tac_handle {int /*<<< orphan*/  user; } ;

/* Variables and functions */
 int save_str (struct tac_handle*,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

int
tac_set_user(struct tac_handle *h, const char *user)
{
	return save_str(h, &h->user, user, user != NULL ? strlen(user) : 0);
}