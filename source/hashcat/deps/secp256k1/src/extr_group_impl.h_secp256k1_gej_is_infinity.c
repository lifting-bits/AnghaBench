#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int infinity; } ;
typedef  TYPE_1__ secp256k1_gej ;

/* Variables and functions */

__attribute__((used)) static int secp256k1_gej_is_infinity(const secp256k1_gej *a) {
    return a->infinity;
}