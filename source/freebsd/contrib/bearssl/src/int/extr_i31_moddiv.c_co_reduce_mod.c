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
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  scalar_t__ int64_t ;

/* Variables and functions */
 int M ; 
 int /*<<< orphan*/  finish_mod (int*,size_t,int const*,int) ; 

__attribute__((used)) static void
co_reduce_mod(uint32_t *a, uint32_t *b, size_t len,
	int64_t pa, int64_t pb, int64_t qa, int64_t qb,
	const uint32_t *m, uint32_t m0i)
{
	size_t k;
	int64_t cca, ccb;
	uint32_t fa, fb;

	cca = 0;
	ccb = 0;
	fa = ((a[0] * (uint32_t)pa + b[0] * (uint32_t)pb) * m0i) & 0x7FFFFFFF;
	fb = ((a[0] * (uint32_t)qa + b[0] * (uint32_t)qb) * m0i) & 0x7FFFFFFF;
	for (k = 0; k < len; k ++) {
		uint32_t wa, wb;
		uint64_t za, zb;
		uint64_t tta, ttb;

		/*
		 * In this loop, carries 'cca' and 'ccb' always fit on
		 * 33 bits (in absolute value).
		 */
		wa = a[k];
		wb = b[k];
		za = wa * (uint64_t)pa + wb * (uint64_t)pb
			+ m[k] * (uint64_t)fa + (uint64_t)cca;
		zb = wa * (uint64_t)qa + wb * (uint64_t)qb
			+ m[k] * (uint64_t)fb + (uint64_t)ccb;
		if (k > 0) {
			a[k - 1] = (uint32_t)za & 0x7FFFFFFF;
			b[k - 1] = (uint32_t)zb & 0x7FFFFFFF;
		}

#define M   ((uint64_t)1 << 32)
		tta = za >> 31;
		ttb = zb >> 31;
		tta = (tta ^ M) - M;
		ttb = (ttb ^ M) - M;
		cca = *(int64_t *)&tta;
		ccb = *(int64_t *)&ttb;
#undef M
	}
	a[len - 1] = (uint32_t)cca;
	b[len - 1] = (uint32_t)ccb;

	/*
	 * At this point:
	 *   -m <= a < 2*m
	 *   -m <= b < 2*m
	 * (this is a case of Montgomery reduction)
	 * The top word of 'a' and 'b' may have a 32-th bit set.
	 * We may have to add or subtract the modulus.
	 */
	finish_mod(a, len, m, (uint32_t)((uint64_t)cca >> 63));
	finish_mod(b, len, m, (uint32_t)((uint64_t)ccb >> 63));
}