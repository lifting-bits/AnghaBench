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
typedef  int /*<<< orphan*/  TestDb ;

/* Variables and functions */
 int tdb_begin (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  testSetError (int) ; 

void testBegin(TestDb *pDb, int iTrans, int *pRc){
  if( *pRc==0 ){
    int rc;
    rc = tdb_begin(pDb, iTrans);
    testSetError(rc);
  }
}