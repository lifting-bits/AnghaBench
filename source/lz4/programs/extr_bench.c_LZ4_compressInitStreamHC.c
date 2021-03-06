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
struct compressionParameters {int /*<<< orphan*/  dictSize; int /*<<< orphan*/  dictBuf; void* LZ4_dictStreamHC; void* LZ4_streamHC; int /*<<< orphan*/ * LZ4_dictStream; int /*<<< orphan*/ * LZ4_stream; } ;

/* Variables and functions */
 void* LZ4_createStreamHC () ; 
 int /*<<< orphan*/  LZ4_loadDictHC (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void LZ4_compressInitStreamHC(
    struct compressionParameters* pThis)
{
    pThis->LZ4_stream = NULL;
    pThis->LZ4_dictStream = NULL;
    pThis->LZ4_streamHC = LZ4_createStreamHC();
    pThis->LZ4_dictStreamHC = LZ4_createStreamHC();
    LZ4_loadDictHC(pThis->LZ4_dictStreamHC, pThis->dictBuf, pThis->dictSize);
}