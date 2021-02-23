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
struct crypt_find_op {int crid; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  CIOCFINDDEV ; 
 int CRYPTO_FLAG_SOFTWARE ; 
 int /*<<< orphan*/  devcrypto () ; 
 int /*<<< orphan*/  err (int,char*) ; 
 int ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct crypt_find_op*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 

int
crlookup(const char *devname)
{
	struct crypt_find_op find;

	if (strncmp(devname, "soft", 4) == 0)
		return CRYPTO_FLAG_SOFTWARE;

	find.crid = -1;
	strlcpy(find.name, devname, sizeof(find.name));
	if (ioctl(devcrypto(), CIOCFINDDEV, &find) == -1)
		err(1, "ioctl(CIOCFINDDEV)");
	return find.crid;
}