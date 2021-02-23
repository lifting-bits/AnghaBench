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
typedef  scalar_t__ y ;
typedef  scalar_t__ x ;
typedef  int ptrdiff_t ;
typedef  int n ;
typedef  int /*<<< orphan*/  __m128d ;

/* Variables and functions */
 int /*<<< orphan*/  _mm_add_pd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_loadu_pd (scalar_t__) ; 
 int /*<<< orphan*/  _mm_set1_pd (double const) ; 
 int /*<<< orphan*/  _mm_storeu_pd (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void THDoubleVector_adds_SSE(double *y, const double *x, const double c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m128d XMM7 = _mm_set1_pd(c);
  __m128d XMM0, XMM2;
  for (i=0; i<=((n)-4); i+=4) {
    XMM0 = _mm_loadu_pd((x)+i);
    XMM2 = _mm_loadu_pd((x)+i+2);
    XMM0 = _mm_add_pd(XMM0, XMM7);
    XMM2 = _mm_add_pd(XMM2, XMM7);
    _mm_storeu_pd((y)+i, XMM0);
    _mm_storeu_pd((y)+i+2, XMM2);
  }
  for (; i<(n); i++) {
    y[i] = x[i] + c;
  }
}