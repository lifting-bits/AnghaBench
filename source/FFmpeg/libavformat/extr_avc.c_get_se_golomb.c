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
typedef  int /*<<< orphan*/  GetBitContext ;

/* Variables and functions */
 int get_ue_golomb (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int get_se_golomb(GetBitContext *gb) {
    int v = get_ue_golomb(gb) + 1;
    int sign = -(v & 1);
    return ((v >> 1) ^ sign) - sign;
}