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
 int BIT_POS (int,int) ; 
 int /*<<< orphan*/  BIT_STR (int,int,int) ; 
 int /*<<< orphan*/  decode_1p_track (int*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  decode_2p_track (int*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void decode_3p_track(int *out, int code, int m, int off) ///code: 3m+1 bits
{
    int half_2p = BIT_POS(code, 2*m - 1) << (m - 1);

    decode_2p_track(out, BIT_STR(code, 0, 2*m - 1),
                    m - 1, off + half_2p);
    decode_1p_track(out + 2, BIT_STR(code, 2*m, m + 1), m, off);
}