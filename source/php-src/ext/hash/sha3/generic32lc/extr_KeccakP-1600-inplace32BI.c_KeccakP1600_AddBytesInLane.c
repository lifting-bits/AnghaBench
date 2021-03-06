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
typedef  int UINT8 ;
typedef  int UINT32 ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int*,unsigned char const*,unsigned int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  toBitInterleavingAndXOR (int,int,int,int,int,int,int) ; 

void KeccakP1600_AddBytesInLane(void *state, unsigned int lanePosition, const unsigned char *data, unsigned int offset, unsigned int length)
{
    UINT8 laneAsBytes[8];
    UINT32 low, high;
    UINT32 temp, temp0, temp1;
    UINT32 *stateAsHalfLanes = (UINT32*)state;

    memset(laneAsBytes, 0, 8);
    memcpy(laneAsBytes+offset, data, length);
#if (PLATFORM_BYTE_ORDER == IS_LITTLE_ENDIAN)
    low = *((UINT32*)(laneAsBytes+0));
    high = *((UINT32*)(laneAsBytes+4));
#else
    low = laneAsBytes[0]
        | ((UINT32)(laneAsBytes[1]) << 8)
        | ((UINT32)(laneAsBytes[2]) << 16)
        | ((UINT32)(laneAsBytes[3]) << 24);
    high = laneAsBytes[4]
        | ((UINT32)(laneAsBytes[5]) << 8)
        | ((UINT32)(laneAsBytes[6]) << 16)
        | ((UINT32)(laneAsBytes[7]) << 24);
#endif
    toBitInterleavingAndXOR(low, high, stateAsHalfLanes[lanePosition*2+0], stateAsHalfLanes[lanePosition*2+1], temp, temp0, temp1);
}