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
struct stat {int dummy; } ;
typedef  int /*<<< orphan*/  isc_boolean_t ;

/* Variables and functions */
 scalar_t__ ISC_R_SUCCESS ; 
 int /*<<< orphan*/  ISC_TF (int) ; 
 int /*<<< orphan*/  REQUIRE (int /*<<< orphan*/ ) ; 
 scalar_t__ file_stats (char const*,struct stat*) ; 

isc_boolean_t
isc_file_exists(const char *pathname) {
	struct stat stats;

	REQUIRE(pathname != NULL);

	return (ISC_TF(file_stats(pathname, &stats) == ISC_R_SUCCESS));
}