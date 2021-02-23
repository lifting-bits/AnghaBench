#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ isNaN; } ;
typedef  TYPE_1__ floatX ;
typedef  int /*<<< orphan*/  float64 ;
typedef  int /*<<< orphan*/  flag ;

/* Variables and functions */
 TYPE_1__ float64ToFloatX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  floatXEq (TYPE_1__,TYPE_1__) ; 
 int /*<<< orphan*/  float_flag_invalid ; 
 int /*<<< orphan*/  slow_float_exception_flags ; 

flag slow_float64_eq_signaling( float64 a, float64 b )
{
    floatX ax, bx;

    ax = float64ToFloatX( a );
    bx = float64ToFloatX( b );
    if ( ax.isNaN || bx.isNaN ) {
        slow_float_exception_flags |= float_flag_invalid;
    }
    return floatXEq( ax, bx );

}