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
typedef  int /*<<< orphan*/  BIGNUM ;

/* Variables and functions */
 int BN_bn2lebinpad (int /*<<< orphan*/  const*,void*,int) ; 
 int BN_num_bytes (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ERR_print_errors_fp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (void*) ; 
 void* malloc (int) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void *
bignum_to_le(const BIGNUM *n)
{
	int blen, error;
	void *rd;

	blen = BN_num_bytes(n);
	if (blen == 0)
		return (NULL);

	rd = malloc(blen);
	if (rd == NULL)
		return (NULL);

	error = BN_bn2lebinpad(n, rd, blen);
	if (error < 0) {
		ERR_print_errors_fp(stderr);
		free(rd);
		return (NULL);
	}

	return (rd);
}