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
typedef  scalar_t__ CORE_ADDR ;

/* Variables and functions */
 unsigned long read_memory_unsigned_integer (scalar_t__,int) ; 

__attribute__((used)) static 
unsigned long read_objc_methlist_nmethods (CORE_ADDR addr)
{
  return read_memory_unsigned_integer (addr + 4, 4);
}