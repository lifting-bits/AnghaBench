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
struct TYPE_4__ {int /*<<< orphan*/  String; } ;
typedef  TYPE_1__ SL_UNICODE ;

/* Variables and functions */
 int /*<<< orphan*/  NdisInitializeString (int /*<<< orphan*/ *,char*) ; 
 TYPE_1__* SlZeroMalloc (int) ; 

SL_UNICODE *SlNewUnicode(char *str)
{
	SL_UNICODE *u;
	// Validate arguments
	if (str == NULL)
	{
		return NULL;
	}

	// Memory allocation
	u = SlZeroMalloc(sizeof(SL_UNICODE));
	if (u == NULL)
	{
		return NULL;
	}

	// String initialization
	NdisInitializeString(&u->String, str);

	return u;
}