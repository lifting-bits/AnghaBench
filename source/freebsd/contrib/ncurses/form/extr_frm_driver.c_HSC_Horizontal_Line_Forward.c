#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* current; } ;
struct TYPE_5__ {int /*<<< orphan*/  cols; } ;
typedef  TYPE_2__ FORM ;

/* Variables and functions */
 int /*<<< orphan*/  HSC_Generic (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  T (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  T_CALLED (char*) ; 
 int /*<<< orphan*/  returnCode (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
HSC_Horizontal_Line_Forward(FORM *form)
{
  T((T_CALLED("HSC_Horizontal_Line_Forward(%p)"), (void *)form));
  returnCode(HSC_Generic(form, form->current->cols));
}