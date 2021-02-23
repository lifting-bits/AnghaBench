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
typedef  scalar_t__ UINT ;
typedef  int /*<<< orphan*/  MSIHANDLE ;

/* Variables and functions */
 scalar_t__ ERROR_SUCCESS ; 
 int /*<<< orphan*/  ok (int,char*,scalar_t__) ; 
 scalar_t__ run_query (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static UINT create_custom_action_table( MSIHANDLE hdb )
{
    UINT r = run_query( hdb,
            "CREATE TABLE `CustomAction` ("
            "`Action` CHAR(72) NOT NULL, "
            "`Type` SHORT NOT NULL, "
            "`Source` CHAR(75), "
            "`Target` CHAR(255) "
            "PRIMARY KEY `Action`)" );
    ok(r == ERROR_SUCCESS, "Failed to create CustomAction table: %u\n", r);
    return r;
}