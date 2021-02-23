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
typedef  int /*<<< orphan*/  text ;
typedef  int /*<<< orphan*/  Oid ;

/* Variables and functions */
 int /*<<< orphan*/  get_tablespace_oid (char*,int) ; 
 char* text_to_cstring (int /*<<< orphan*/ *) ; 

__attribute__((used)) static Oid
convert_tablespace_name(text *tablespacename)
{
	char	   *spcname = text_to_cstring(tablespacename);

	return get_tablespace_oid(spcname, false);
}