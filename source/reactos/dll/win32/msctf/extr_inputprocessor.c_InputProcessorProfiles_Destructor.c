#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  LanguageProfileNotifySink; } ;
typedef  TYPE_1__ InputProcessorProfiles ;

/* Variables and functions */
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  TRACE (char*,TYPE_1__*) ; 
 int /*<<< orphan*/  free_sinks (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void InputProcessorProfiles_Destructor(InputProcessorProfiles *This)
{
    TRACE("destroying %p\n", This);

    free_sinks(&This->LanguageProfileNotifySink);
    HeapFree(GetProcessHeap(),0,This);
}