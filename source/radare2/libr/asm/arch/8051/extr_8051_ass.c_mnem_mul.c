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
typedef  int /*<<< orphan*/  ut16 ;

/* Variables and functions */
 scalar_t__ r_str_ncasecmp (char*,char const* const,int) ; 
 int single_byte_instr (int,int /*<<< orphan*/ **) ; 

__attribute__((used)) static bool mnem_mul(char const*const*arg, ut16 pc, ut8**out) {
	if (r_str_ncasecmp ("ab", arg[0], 3)) {
		return false;
	}
	return single_byte_instr (0xa4, out);
}