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

/* Variables and functions */
 int sdb_grep_dump (char const*,int,int,char const*) ; 

__attribute__((used)) static int sdb_grep(const char *db, int fmt, const char *grep) {
	return sdb_grep_dump (db, fmt, true, grep);
}