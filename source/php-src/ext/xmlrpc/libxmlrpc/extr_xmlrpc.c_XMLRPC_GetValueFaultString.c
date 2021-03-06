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
typedef  int /*<<< orphan*/  XMLRPC_VALUE ;

/* Variables and functions */
 char const* XMLRPC_VectorGetStringWithID (int /*<<< orphan*/ ,char*) ; 

const char* XMLRPC_GetValueFaultString (XMLRPC_VALUE value) {
   return XMLRPC_VectorGetStringWithID(value, "faultString");
}