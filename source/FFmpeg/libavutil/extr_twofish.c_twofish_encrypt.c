#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
struct TYPE_4__ {int* K; } ;
typedef  TYPE_1__ AVTWOFISH ;

/* Variables and functions */
 int AV_RL32 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  AV_WL32 (int /*<<< orphan*/ *,int) ; 
 int LR (int,int) ; 
 int MDS_mul (TYPE_1__*,int) ; 
 int RR (int,int) ; 

__attribute__((used)) static void twofish_encrypt(AVTWOFISH *cs, uint8_t *dst, const uint8_t *src)
{
    uint32_t P[4], t0, t1;
    int i;
    P[0] = AV_RL32(src) ^ cs->K[0];
    P[1] = AV_RL32(src + 4) ^ cs->K[1];
    P[2] = AV_RL32(src + 8) ^ cs->K[2];
    P[3] = AV_RL32(src + 12) ^ cs->K[3];
    for (i = 0; i < 16; i += 2) {
        t0 = MDS_mul(cs, P[0]);
        t1 = MDS_mul(cs, LR(P[1], 8));
        P[2] = RR(P[2] ^ (t0 + t1 + cs->K[2 * i + 8]), 1);
        P[3] = LR(P[3], 1) ^ (t0 + 2 * t1 + cs->K[2 * i + 9]);
        t0 = MDS_mul(cs, P[2]);
        t1 = MDS_mul(cs, LR(P[3], 8));
        P[0] = RR(P[0] ^ (t0 + t1 + cs->K[2 * i + 10]), 1);
        P[1] = LR(P[1], 1) ^ (t0 + 2 * t1 + cs->K[2 * i + 11]);
    }
    P[2] ^= cs->K[4];
    P[3] ^= cs->K[5];
    P[0] ^= cs->K[6];
    P[1] ^= cs->K[7];
    AV_WL32(dst, P[2]);
    AV_WL32(dst + 4, P[3]);
    AV_WL32(dst + 8, P[0]);
    AV_WL32(dst + 12, P[1]);
}