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
struct TYPE_4__ {TYPE_1__* tdt; } ;
struct TYPE_3__ {int stop; int start; } ;

/* Variables and functions */
 TYPE_2__* bcom_eng ; 

__attribute__((used)) static inline int
bcom_task_num_descs(int task)
{
	return (bcom_eng->tdt[task].stop - bcom_eng->tdt[task].start)/sizeof(u32) + 1;
}