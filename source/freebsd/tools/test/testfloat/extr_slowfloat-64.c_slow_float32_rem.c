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
typedef  int /*<<< orphan*/  float32 ;

/* Variables and functions */
 int /*<<< orphan*/  float32ToFloatX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  floatXRem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  floatXToFloat32 (int /*<<< orphan*/ ) ; 

float32 slow_float32_rem( float32 a, float32 b )
{

    return
        floatXToFloat32(
            floatXRem( float32ToFloatX( a ), float32ToFloatX( b ) ) );

}