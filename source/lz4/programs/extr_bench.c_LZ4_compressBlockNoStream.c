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
struct compressionParameters {int cLevel; } ;

/* Variables and functions */
 int LZ4_compress_fast (char const*,char*,int,int,int const) ; 

__attribute__((used)) static int LZ4_compressBlockNoStream(
    const struct compressionParameters* pThis,
    const char* src, char* dst,
    int srcSize, int dstSize)
{
    int const acceleration = (pThis->cLevel < 0) ? -pThis->cLevel + 1 : 1;
    return LZ4_compress_fast(src, dst, srcSize, dstSize, acceleration);
}