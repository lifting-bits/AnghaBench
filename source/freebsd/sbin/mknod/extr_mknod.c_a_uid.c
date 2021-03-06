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
typedef  int /*<<< orphan*/  uid_t ;
struct passwd {int /*<<< orphan*/  pw_uid; } ;

/* Variables and functions */
 int /*<<< orphan*/  errx (int,char*) ; 
 struct passwd* getpwnam (char const*) ; 
 int /*<<< orphan*/  id (char const*,char*) ; 

__attribute__((used)) static uid_t
a_uid(const char *s)
{
	struct passwd *pw;

	if (*s == '\0')			/* Argument was "[:.]gid". */
		errx(1, "owner must be specified when the group is");
	return ((pw = getpwnam(s)) == NULL) ? id(s, "user") : pw->pw_uid;
}