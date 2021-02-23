#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct _fts3ht {scalar_t__ count; TYPE_2__* chain; } ;
struct TYPE_10__ {scalar_t__ count; scalar_t__ first; scalar_t__ copyKey; struct _fts3ht* ht; } ;
struct TYPE_9__ {struct TYPE_9__* pKey; struct TYPE_9__* next; TYPE_1__* prev; } ;
struct TYPE_8__ {TYPE_2__* next; } ;
typedef  TYPE_2__ Fts3HashElem ;
typedef  TYPE_3__ Fts3Hash ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  fts3HashClear (TYPE_3__*) ; 
 int /*<<< orphan*/  fts3HashFree (TYPE_2__*) ; 

__attribute__((used)) static void fts3RemoveElementByHash(
  Fts3Hash *pH,         /* The pH containing "elem" */
  Fts3HashElem* elem,   /* The element to be removed from the pH */
  int h                 /* Hash value for the element */
){
  struct _fts3ht *pEntry;
  if( elem->prev ){
    elem->prev->next = elem->next; 
  }else{
    pH->first = elem->next;
  }
  if( elem->next ){
    elem->next->prev = elem->prev;
  }
  pEntry = &pH->ht[h];
  if( pEntry->chain==elem ){
    pEntry->chain = elem->next;
  }
  pEntry->count--;
  if( pEntry->count<=0 ){
    pEntry->chain = 0;
  }
  if( pH->copyKey && elem->pKey ){
    fts3HashFree(elem->pKey);
  }
  fts3HashFree( elem );
  pH->count--;
  if( pH->count<=0 ){
    assert( pH->first==0 );
    assert( pH->count==0 );
    fts3HashClear(pH);
  }
}