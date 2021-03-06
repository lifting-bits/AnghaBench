#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int i64 ;
struct TYPE_3__ {scalar_t__ eState; scalar_t__ eLock; scalar_t__ tempFile; int pageSize; scalar_t__ mxPgno; int /*<<< orphan*/  fd; int /*<<< orphan*/  pWal; } ;
typedef  scalar_t__ Pgno ;
typedef  TYPE_1__ Pager ;

/* Variables and functions */
 scalar_t__ ALWAYS (int) ; 
 scalar_t__ PAGER_OPEN ; 
 scalar_t__ SHARED_LOCK ; 
 int SQLITE_OK ; 
 int /*<<< orphan*/  assert (int) ; 
 int isOpen (int /*<<< orphan*/ ) ; 
 int sqlite3OsFileSize (int /*<<< orphan*/ ,int*) ; 
 scalar_t__ sqlite3WalDbsize (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int pagerPagecount(Pager *pPager, Pgno *pnPage){
  Pgno nPage;                     /* Value to return via *pnPage */

  /* Query the WAL sub-system for the database size. The WalDbsize()
  ** function returns zero if the WAL is not open (i.e. Pager.pWal==0), or
  ** if the database size is not available. The database size is not
  ** available from the WAL sub-system if the log file is empty or
  ** contains no valid committed transactions.
  */
  assert( pPager->eState==PAGER_OPEN );
  assert( pPager->eLock>=SHARED_LOCK );
  assert( isOpen(pPager->fd) );
  assert( pPager->tempFile==0 );
  nPage = sqlite3WalDbsize(pPager->pWal);

  /* If the number of pages in the database is not available from the
  ** WAL sub-system, determine the page count based on the size of
  ** the database file.  If the size of the database file is not an
  ** integer multiple of the page-size, round up the result.
  */
  if( nPage==0 && ALWAYS(isOpen(pPager->fd)) ){
    i64 n = 0;                    /* Size of db file in bytes */
    int rc = sqlite3OsFileSize(pPager->fd, &n);
    if( rc!=SQLITE_OK ){
      return rc;
    }
    nPage = (Pgno)((n+pPager->pageSize-1) / pPager->pageSize);
  }

  /* If the current number of pages in the file is greater than the
  ** configured maximum pager number, increase the allowed limit so
  ** that the file can be read.
  */
  if( nPage>pPager->mxPgno ){
    pPager->mxPgno = (Pgno)nPage;
  }

  *pnPage = nPage;
  return SQLITE_OK;
}