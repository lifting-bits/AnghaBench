#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {char* updateEnd; } ;
typedef  TYPE_1__ SDbObj ;

/* Variables and functions */
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memcpy (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 

void *mgmtDbActionDecode(void *row, char *str, int size, int *ssize) {
  SDbObj *pDb = (SDbObj *)malloc(sizeof(SDbObj));
  if (pDb == NULL) return NULL;
  memset(pDb, 0, sizeof(SDbObj));

  int tsize = pDb->updateEnd - (char *)pDb;
  memcpy(pDb, str, tsize);

  return (void *)pDb;
}