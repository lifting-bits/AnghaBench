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

/* Variables and functions */
 int /*<<< orphan*/  PUTBYTE (unsigned int) ; 

__attribute__((used)) static void
write_2_bytes (unsigned int val)
{
  PUTBYTE((val >> 8) & 0xFF);
  PUTBYTE(val & 0xFF);
}