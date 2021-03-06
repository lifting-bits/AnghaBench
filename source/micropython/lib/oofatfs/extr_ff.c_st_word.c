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
typedef  int WORD ;
typedef  void* BYTE ;

/* Variables and functions */

__attribute__((used)) static void st_word (BYTE* ptr, WORD val)   /* Store a 2-byte word in little-endian */
{
    *ptr++ = (BYTE)val; val >>= 8;
    *ptr++ = (BYTE)val;
}