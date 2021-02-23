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
typedef  int /*<<< orphan*/  RDFTContext ;

/* Variables and functions */
 int /*<<< orphan*/  av_rdft_end (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ff_rdft_end (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void rdft_end(RDFTContext *r)
{
#if AVFFT
    av_rdft_end(r);
#else
    ff_rdft_end(r);
#endif
}