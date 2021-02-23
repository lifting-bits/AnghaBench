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
typedef  int uint32_t ;
typedef  int u_int ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int MAX_PKRU_IDX ; 
 int /*<<< orphan*/  errno ; 
 int rdpkru () ; 
 int /*<<< orphan*/  wrpkru (int) ; 

__attribute__((used)) static int
x86_pkru_set_perm_hw(u_int keyidx, int access, int modify)
{
	uint32_t pkru;

	if (keyidx > MAX_PKRU_IDX) {
		errno = EINVAL;
		return (-1);
	}
	keyidx *= 2;
	pkru = rdpkru();
	pkru &= ~(3 << keyidx);
	if (!access)
		pkru |= 1 << keyidx;
	if (!modify)
		pkru |= 2 << keyidx;
	wrpkru(pkru);
	return (0);
}