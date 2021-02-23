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
typedef  int /*<<< orphan*/  EditDist3Config ;

/* Variables and functions */
 int /*<<< orphan*/  editDist3ConfigClear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqlite3_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void editDist3ConfigDelete(void *pIn){
  EditDist3Config *p = (EditDist3Config*)pIn;
  editDist3ConfigClear(p);
  sqlite3_free(p);
}