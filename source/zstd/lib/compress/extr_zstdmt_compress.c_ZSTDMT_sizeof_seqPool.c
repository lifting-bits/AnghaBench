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
typedef  int /*<<< orphan*/  ZSTDMT_seqPool ;

/* Variables and functions */
 size_t ZSTDMT_sizeof_bufferPool (int /*<<< orphan*/ *) ; 

__attribute__((used)) static size_t ZSTDMT_sizeof_seqPool(ZSTDMT_seqPool* seqPool)
{
    return ZSTDMT_sizeof_bufferPool(seqPool);
}