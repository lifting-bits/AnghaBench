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
struct nstat_tucookie {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nstat_tucookie_release_internal (struct nstat_tucookie*,int) ; 

__attribute__((used)) static void
nstat_tucookie_release(
    struct nstat_tucookie *cookie)
{
	nstat_tucookie_release_internal(cookie, false);
}