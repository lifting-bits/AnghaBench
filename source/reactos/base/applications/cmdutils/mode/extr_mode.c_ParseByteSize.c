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
typedef  int /*<<< orphan*/ * PCWSTR ;
typedef  int* PBYTE ;
typedef  scalar_t__ DWORD ;
typedef  int BYTE ;

/* Variables and functions */
 int /*<<< orphan*/ * ParseNumber (int /*<<< orphan*/ *,scalar_t__*) ; 

__attribute__((used)) static PCWSTR
ParseByteSize(PCWSTR argStr, PBYTE ByteSize)
{
    DWORD value = 0;

    argStr = ParseNumber(argStr, &value);
    if (!argStr) return NULL;

    *ByteSize = (BYTE)value;
    if (*ByteSize < 5 || *ByteSize > 8)
        return NULL;

    return argStr;
}