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
typedef  int /*<<< orphan*/  i ;

/* Variables and functions */
 scalar_t__ asprintf (char**,char*,char const*) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ sysctlbyname (char*,int*,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int
feature_present(const char *feature)
{
	char *mib;
	size_t len;
	int i;

	if (asprintf(&mib, "kern.features.%s", feature) < 0)
		return (0);
	len = sizeof(i);
	if (sysctlbyname(mib, &i, &len, NULL, 0) < 0) {
		free(mib);
		return (0);
	}
	free(mib);
	if (len != sizeof(i))
		return (0);
	return (i != 0);
}