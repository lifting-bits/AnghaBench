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
typedef  int /*<<< orphan*/ * uECC_Curve ;

/* Variables and functions */
 int /*<<< orphan*/  curve_secp256r1 ; 

uECC_Curve uECC_secp256r1(void) { return &curve_secp256r1; }