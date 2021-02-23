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
typedef  int /*<<< orphan*/  cmsUInt16Number ;
typedef  float cmsFloat32Number ;

/* Variables and functions */
 float CHANGE_ENDIAN (int /*<<< orphan*/ ) ; 

__attribute__((used)) static
void from16SEtoFLT(void* dst, const void* src)
{
    *(cmsFloat32Number*)dst = (CHANGE_ENDIAN(*(cmsUInt16Number*)src)) / 65535.0f;
}