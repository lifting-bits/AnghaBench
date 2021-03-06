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
typedef  int /*<<< orphan*/  uint32 ;
typedef  int /*<<< orphan*/  int32 ;
typedef  int /*<<< orphan*/  MultiConnection ;

/* Variables and functions */
 int /*<<< orphan*/ * StartNodeUserDatabaseConnection (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

MultiConnection *
StartNodeConnection(uint32 flags, const char *hostname, int32 port)
{
	return StartNodeUserDatabaseConnection(flags, hostname, port, NULL, NULL);
}