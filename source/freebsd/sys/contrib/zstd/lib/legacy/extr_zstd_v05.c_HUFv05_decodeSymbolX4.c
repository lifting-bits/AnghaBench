#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  U32 ;
struct TYPE_4__ {int /*<<< orphan*/  length; int /*<<< orphan*/  nbBits; } ;
typedef  TYPE_1__ HUFv05_DEltX4 ;
typedef  int /*<<< orphan*/  BITv05_DStream_t ;

/* Variables and functions */
 size_t BITv05_lookBitsFast (int /*<<< orphan*/ *,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  BITv05_skipBits (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,TYPE_1__ const*,int) ; 

__attribute__((used)) static U32 HUFv05_decodeSymbolX4(void* op, BITv05_DStream_t* DStream, const HUFv05_DEltX4* dt, const U32 dtLog)
{
    const size_t val = BITv05_lookBitsFast(DStream, dtLog);   /* note : dtLog >= 1 */
    memcpy(op, dt+val, 2);
    BITv05_skipBits(DStream, dt[val].nbBits);
    return dt[val].length;
}