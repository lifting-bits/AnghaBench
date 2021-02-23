#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  e ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_4__ {int /*<<< orphan*/  Id; } ;
typedef  TYPE_1__ LANGLIST ;

/* Variables and functions */
 int /*<<< orphan*/  GetCurrentOsLang (TYPE_1__*) ; 
 int /*<<< orphan*/  Zero (TYPE_1__*,int) ; 

UINT GetCurrentOsLangId()
{
	LANGLIST e;

	Zero(&e, sizeof(e));

	GetCurrentOsLang(&e);

	return e.Id;
}