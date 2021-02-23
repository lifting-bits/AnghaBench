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
typedef  int /*<<< orphan*/  float32 ;

/* Variables and functions */
 int /*<<< orphan*/  float64ToFloatX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  floatXToFloat32 (int /*<<< orphan*/ ) ; 

float32 slow_float64_to_float32( float64 a )
{

    return floatXToFloat32( float64ToFloatX( a ) );

}