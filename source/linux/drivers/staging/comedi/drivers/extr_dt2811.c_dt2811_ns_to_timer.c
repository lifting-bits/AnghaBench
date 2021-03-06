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

/* Variables and functions */
#define  CMDF_ROUND_DOWN 130 
 unsigned int CMDF_ROUND_MASK ; 
#define  CMDF_ROUND_NEAREST 129 
#define  CMDF_ROUND_UP 128 
 unsigned long long COMEDI_MIN_SPEED ; 
 unsigned long long DT2811_OSC_BASE ; 
 unsigned int DT2811_TMRCTR_EXPONENT (unsigned int) ; 
 unsigned int DT2811_TMRCTR_MANTISSA (unsigned int) ; 
 unsigned int* dt2811_clk_dividers ; 
 unsigned int* dt2811_clk_multipliers ; 

__attribute__((used)) static unsigned int dt2811_ns_to_timer(unsigned int *nanosec,
				       unsigned int flags)
{
	unsigned long long ns;
	unsigned int ns_lo = COMEDI_MIN_SPEED;
	unsigned int ns_hi = 0;
	unsigned int divisor_hi = 0;
	unsigned int divisor_lo = 0;
	unsigned int _div;
	unsigned int _mult;

	/*
	 * Work through all the divider/multiplier values to find the two
	 * closest divisors to generate the requested nanosecond timing.
	 */
	for (_div = 0; _div <= 7; _div++) {
		for (_mult = 0; _mult <= 7; _mult++) {
			unsigned int div = dt2811_clk_dividers[_div];
			unsigned int mult = dt2811_clk_multipliers[_mult];
			unsigned long long divider = div * mult;
			unsigned int divisor = DT2811_TMRCTR_MANTISSA(_div) |
					       DT2811_TMRCTR_EXPONENT(_mult);

			/*
			 * The timer can be configured to run at a slowest
			 * speed of 0.005hz (600 Khz/120000000), which requires
			 * 37-bits to represent the nanosecond value. Limit the
			 * slowest timing to what comedi handles (32-bits).
			 */
			ns = divider * DT2811_OSC_BASE;
			if (ns > COMEDI_MIN_SPEED)
				continue;

			/* Check for fastest found timing */
			if (ns <= *nanosec && ns > ns_hi) {
				ns_hi = ns;
				divisor_hi = divisor;
			}
			/* Check for slowest found timing */
			if (ns >= *nanosec && ns < ns_lo) {
				ns_lo = ns;
				divisor_lo = divisor;
			}
		}
	}

	/*
	 * The slowest found timing will be invalid if the requested timing
	 * is faster than what can be generated by the timer. Fix it so that
	 * CMDF_ROUND_UP returns valid timing.
	 */
	if (ns_lo == COMEDI_MIN_SPEED) {
		ns_lo = ns_hi;
		divisor_lo = divisor_hi;
	}
	/*
	 * The fastest found timing will be invalid if the requested timing
	 * is less than what can be generated by the timer. Fix it so that
	 * CMDF_ROUND_NEAREST and CMDF_ROUND_DOWN return valid timing.
	 */
	if (ns_hi == 0) {
		ns_hi = ns_lo;
		divisor_hi = divisor_lo;
	}

	switch (flags & CMDF_ROUND_MASK) {
	case CMDF_ROUND_NEAREST:
	default:
		if (ns_hi - *nanosec < *nanosec - ns_lo) {
			*nanosec = ns_lo;
			return divisor_lo;
		}
		*nanosec = ns_hi;
		return divisor_hi;
	case CMDF_ROUND_UP:
		*nanosec = ns_lo;
		return divisor_lo;
	case CMDF_ROUND_DOWN:
		*nanosec = ns_hi;
		return divisor_hi;
	}
}