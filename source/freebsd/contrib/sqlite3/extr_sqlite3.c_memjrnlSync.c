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
typedef  int /*<<< orphan*/  sqlite3_file ;

/* Variables and functions */
 int SQLITE_OK ; 
 int /*<<< orphan*/  UNUSED_PARAMETER2 (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int memjrnlSync(sqlite3_file *pJfd, int flags){
  UNUSED_PARAMETER2(pJfd, flags);
  return SQLITE_OK;
}