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
typedef  int /*<<< orphan*/  Datasource ;

/* Variables and functions */
 int tdb_lsm_open (char const*,char const*,int,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  testClose (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  testSaveDb (char const*,char*) ; 
 int /*<<< orphan*/  testWriteDatasourceRange (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int*) ; 

void testSetupSavedLsmdb(
  const char *zCfg,
  const char *zFile,
  Datasource *pData,
  int nRow,
  int *pRc
){
  if( *pRc==0 ){
    int rc;
    TestDb *pDb;
    rc = tdb_lsm_open(zCfg, zFile, 1, &pDb);
    if( rc==0 ){
      testWriteDatasourceRange(pDb, pData, 0, nRow, &rc);
      testClose(&pDb);
      if( rc==0 ) testSaveDb(zFile, "log");
    }
    *pRc = rc;
  }
}