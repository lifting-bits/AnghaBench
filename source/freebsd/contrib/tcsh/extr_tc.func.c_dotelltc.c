#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/ * command ;
typedef  int /*<<< orphan*/  Char ;

/* Variables and functions */
 int /*<<< orphan*/  GetTermCaps () ; 
 int /*<<< orphan*/  GotTermCaps ; 
 int /*<<< orphan*/  TellTC () ; 
 int /*<<< orphan*/  USE (int /*<<< orphan*/ **) ; 

void
dotelltc(Char **v, struct command *c)
{
    USE(v);
    USE(c);
    if (!GotTermCaps)
	GetTermCaps();
    TellTC();
}