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
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  RCrypto ;

/* Variables and functions */
 int /*<<< orphan*/ * calloc (int,int) ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 scalar_t__ flag ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_crypto_append (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ror_crypt (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  st ; 

__attribute__((used)) static bool update(RCrypto *cry, const ut8 *buf, int len) {
	if (flag) {
		eprintf ("USE ROL\n");
		return false;
	}
	ut8 *obuf = calloc (1, len);
	if (!obuf) {
		return false;
	}
	ror_crypt (&st, buf, obuf, len);
	r_crypto_append (cry, obuf, len);
	free (obuf);
	return true;
}