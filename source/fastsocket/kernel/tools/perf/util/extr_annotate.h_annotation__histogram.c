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
typedef  void sym_hist ;
struct annotation {TYPE_1__* src; } ;
struct TYPE_2__ {int sizeof_sym_hist; int /*<<< orphan*/  histograms; } ;

/* Variables and functions */

__attribute__((used)) static inline struct sym_hist *annotation__histogram(struct annotation *notes, int idx)
{
	return (((void *)&notes->src->histograms) +
	 	(notes->src->sizeof_sym_hist * idx));
}