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
typedef  int /*<<< orphan*/  float64 ;

/* Variables and functions */
 int /*<<< orphan*/  LIT64 (int) ; 
 int /*<<< orphan*/  float64ToFloatX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  floatXAdd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  floatXToFloat64 (int /*<<< orphan*/ ) ; 

float64 slow_float64_sub( float64 a, float64 b )
{

    b ^= LIT64( 0x8000000000000000 );
    return
        floatXToFloat64(
            floatXAdd( float64ToFloatX( a ), float64ToFloatX( b ) ) );

}