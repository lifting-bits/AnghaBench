#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  void* hook_p ;
typedef  TYPE_2__* hinfo_p ;
struct TYPE_5__ {void* nomatch; TYPE_1__* prog; void* match; } ;
struct TYPE_4__ {int /*<<< orphan*/  ifNotMatch; int /*<<< orphan*/  ifMatch; } ;

/* Variables and functions */
 int /*<<< orphan*/  NG_HOOK_NAME (void*) ; 
 TYPE_2__* NG_HOOK_PRIVATE (void*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ng_bpf_addrefs(hook_p hook, void* arg)
{
	hinfo_p hip = NG_HOOK_PRIVATE(hook);
	hook_p h = (hook_p)arg;

	if (strcmp(hip->prog->ifMatch, NG_HOOK_NAME(h)) == 0)
	    hip->match = h;
	if (strcmp(hip->prog->ifNotMatch, NG_HOOK_NAME(h)) == 0)
	    hip->nomatch = h;
	return (1);
}