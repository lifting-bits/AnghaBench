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
struct TYPE_2__ {scalar_t__ (* Busy ) (TYPE_1__*) ;} ;
struct riva_par {TYPE_1__ riva; } ;

/* Variables and functions */
 scalar_t__ stub1 (TYPE_1__*) ; 

__attribute__((used)) static inline void wait_for_idle(struct riva_par *par)
{
	while (par->riva.Busy(&par->riva));
}