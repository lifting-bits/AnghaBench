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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  GetByteContext ;

/* Variables and functions */
 unsigned int bytestream2_get_le32 (int /*<<< orphan*/ *) ; 
 int snappy_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,unsigned int,int) ; 

__attribute__((used)) static int snappy_copy4(GetByteContext *gb, uint8_t *start, uint8_t *p,
                        int size, int val)
{
    int len          = 1 + val;
    unsigned int off = bytestream2_get_le32(gb);

    return snappy_copy(start, p, size, off, len);
}