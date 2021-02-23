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
struct url_stat {int dummy; } ;
struct url {int dummy; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  http_get_proxy (struct url*,char const*) ; 
 int /*<<< orphan*/ * http_request (struct url*,char*,struct url_stat*,int /*<<< orphan*/ ,char const*) ; 

int
fetchStatHTTP(struct url *URL, struct url_stat *us, const char *flags)
{
	FILE *f;

	f = http_request(URL, "HEAD", us, http_get_proxy(URL, flags), flags);
	if (f == NULL)
		return (-1);
	fclose(f);
	return (0);
}