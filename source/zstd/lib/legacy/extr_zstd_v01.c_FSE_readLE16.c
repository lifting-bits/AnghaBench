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
typedef  int /*<<< orphan*/  U16 ;
typedef  int BYTE ;

/* Variables and functions */
 scalar_t__ FSE_isLittleEndian () ; 
 int /*<<< orphan*/  FSE_read16 (void const*) ; 

__attribute__((used)) static U16 FSE_readLE16(const void* memPtr)
{
    if (FSE_isLittleEndian())
        return FSE_read16(memPtr);
    else
    {
        const BYTE* p = (const BYTE*)memPtr;
        return (U16)(p[0] + (p[1]<<8));
    }
}