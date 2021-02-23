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
typedef  int /*<<< orphan*/  int8 ;
typedef  int /*<<< orphan*/  int32 ;
typedef  int /*<<< orphan*/  float64 ;

/* Variables and functions */
 int /*<<< orphan*/  float64ToFloatX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  floatXToInt32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  float_round_to_zero ; 
 int /*<<< orphan*/  slow_float_rounding_mode ; 

int32 slow_float64_to_int32_round_to_zero( float64 a )
{
    int8 savedRoundingMode;
    int32 z;

    savedRoundingMode = slow_float_rounding_mode;
    slow_float_rounding_mode = float_round_to_zero;
    z = floatXToInt32( float64ToFloatX( a ) );
    slow_float_rounding_mode = savedRoundingMode;
    return z;

}