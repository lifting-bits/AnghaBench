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
struct passwd {int dummy; } ;
typedef  int /*<<< orphan*/  cap_channel_t ;

/* Variables and functions */
 struct passwd* cap_getpwcommon (int /*<<< orphan*/ *,char*,char const*,int /*<<< orphan*/ ) ; 

struct passwd *
cap_getpwnam(cap_channel_t *chan, const char *login)
{

	return (cap_getpwcommon(chan, "getpwnam", login, 0));
}