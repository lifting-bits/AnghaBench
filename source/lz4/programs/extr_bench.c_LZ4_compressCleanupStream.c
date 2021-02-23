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
struct compressionParameters {int /*<<< orphan*/  LZ4_dictStream; int /*<<< orphan*/  LZ4_stream; } ;

/* Variables and functions */
 int /*<<< orphan*/  LZ4_freeStream (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void LZ4_compressCleanupStream(
    const struct compressionParameters* pThis)
{
    LZ4_freeStream(pThis->LZ4_stream);
    LZ4_freeStream(pThis->LZ4_dictStream);
}