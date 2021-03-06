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
struct pcg_state_setseq_128 {unsigned int state; unsigned int inc; } ;
typedef  unsigned int pcg128_t ;

/* Variables and functions */
 int /*<<< orphan*/  pcg_setseq_128_step_r (struct pcg_state_setseq_128*) ; 

inline void pcg_setseq_128_srandom_r(struct pcg_state_setseq_128 *rng,
                                     pcg128_t initstate, pcg128_t initseq) {
  rng->state = 0U;
  rng->inc = (initseq << 1u) | 1u;
  pcg_setseq_128_step_r(rng);
  rng->state += initstate;
  pcg_setseq_128_step_r(rng);
}