#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {TYPE_3__* pTscObj; } ;
struct TYPE_11__ {scalar_t__ listed; TYPE_2__* prev; TYPE_1__* next; } ;
struct TYPE_10__ {int /*<<< orphan*/  mutex; TYPE_1__* streamList; } ;
struct TYPE_9__ {TYPE_1__* next; } ;
struct TYPE_8__ {TYPE_2__* prev; } ;
typedef  TYPE_3__ STscObj ;
typedef  TYPE_4__ SSqlStream ;
typedef  TYPE_5__ SSqlObj ;

/* Variables and functions */
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

void tscRemoveFromStreamList(SSqlStream *pStream, SSqlObj *pSqlObj) {
  if (pStream->listed == 0) return;

  STscObj *pObj = pSqlObj->pTscObj;

  pthread_mutex_lock(&pObj->mutex);

  if (pStream->prev)
    pStream->prev->next = pStream->next;
  else
    pObj->streamList = pStream->next;

  if (pStream->next) pStream->next->prev = pStream->prev;

  pthread_mutex_unlock(&pObj->mutex);

  pStream->next = NULL;
  pStream->prev = NULL;

  pStream->listed = 0;
}