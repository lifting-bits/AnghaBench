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
typedef  int DWORD_PTR ;
typedef  int BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  VNSvInPortB (int,int*) ; 

BOOL MACbIsRegBitsOff (DWORD_PTR dwIoBase, BYTE byRegOfs, BYTE byTestBits)
{
    BYTE byData;

    VNSvInPortB(dwIoBase + byRegOfs, &byData);
    return !(byData & byTestBits);
}