#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_2__ {int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ t_QmCg ;
typedef  scalar_t__ t_Handle ;

/* Variables and functions */

__attribute__((used)) static uint8_t QmCgGetCgId(t_Handle h_QmCg)
{
   t_QmCg *p_QmCg = (t_QmCg *)h_QmCg;

   return p_QmCg->id;

}