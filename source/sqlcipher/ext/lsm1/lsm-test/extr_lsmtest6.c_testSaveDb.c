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
 int /*<<< orphan*/  copy_file (char const*,char*,int) ; 
 int /*<<< orphan*/  testFree (char*) ; 
 char* testMallocPrintf (char*,char const*,...) ; 
 int /*<<< orphan*/  unlink (char*) ; 

void testSaveDb(const char *zFile, const char *zAux){
  char *zLog = testMallocPrintf("%s-%s", zFile, zAux);
  char *zFileSave = testMallocPrintf("%s-save", zFile);
  char *zLogSave = testMallocPrintf("%s-%s-save", zFile, zAux);

  unlink(zFileSave);
  unlink(zLogSave);
  copy_file(zFile, zFileSave, 1);
  copy_file(zLog, zLogSave, 0);

  testFree(zLog); testFree(zFileSave); testFree(zLogSave);
}