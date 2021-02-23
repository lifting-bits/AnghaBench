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
 int /*<<< orphan*/  e7000_desc ; 
 int /*<<< orphan*/  serial_write (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static void
putchar_e7000 (int x)
{
  char b[1];

  b[0] = x;
  serial_write (e7000_desc, b, 1);
}