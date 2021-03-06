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
struct TYPE_6__ {struct TYPE_6__* Next; } ;
struct TYPE_5__ {TYPE_2__* FreeCommands; } ;
typedef  TYPE_1__ DAC960_Controller_T ;
typedef  TYPE_2__ DAC960_Command_T ;

/* Variables and functions */

__attribute__((used)) static inline DAC960_Command_T *DAC960_AllocateCommand(DAC960_Controller_T
						       *Controller)
{
  DAC960_Command_T *Command = Controller->FreeCommands;
  if (Command == NULL) return NULL;
  Controller->FreeCommands = Command->Next;
  Command->Next = NULL;
  return Command;
}