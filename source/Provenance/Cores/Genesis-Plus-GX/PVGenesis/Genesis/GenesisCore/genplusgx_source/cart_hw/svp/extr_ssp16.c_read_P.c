#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_3__ {int /*<<< orphan*/  h; } ;
struct TYPE_4__ {int v; TYPE_1__ byte; } ;

/* Variables and functions */
 TYPE_2__ rP ; 
 scalar_t__ rX ; 
 scalar_t__ rY ; 

__attribute__((used)) static u32 read_P(void)
{
  int m1 = (signed short)rX;
  int m2 = (signed short)rY;
  rP.v = (m1 * m2 * 2);
  return rP.byte.h;
}