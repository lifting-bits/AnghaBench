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
typedef  int UInt32 ;
typedef  scalar_t__ UChar ;
typedef  int Int32 ;
typedef  int /*<<< orphan*/  BitStream ;

/* Variables and functions */
 int /*<<< orphan*/  bsPutBit (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void bsPutUChar ( BitStream* bs, UChar c )
{
   Int32 i;
   for (i = 7; i >= 0; i--)
      bsPutBit ( bs, (((UInt32) c) >> i) & 0x1 );
}