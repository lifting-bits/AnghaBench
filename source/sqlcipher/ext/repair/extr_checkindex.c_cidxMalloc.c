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
 int SQLITE_NOMEM ; 
 int SQLITE_OK ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 void* sqlite3_malloc (int) ; 

__attribute__((used)) static void *cidxMalloc(int *pRc, int n){
  void *pRet = 0;
  assert( n!=0 );
  if( *pRc==SQLITE_OK ){
    pRet = sqlite3_malloc(n);
    if( pRet ){
      memset(pRet, 0, n);
    }else{
      *pRc = SQLITE_NOMEM;
    }
  }
  return pRet;
}