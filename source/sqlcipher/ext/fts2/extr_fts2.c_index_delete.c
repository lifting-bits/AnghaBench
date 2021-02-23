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
typedef  int /*<<< orphan*/  sqlite_int64 ;
typedef  int /*<<< orphan*/  fulltext_vtab ;

/* Variables and functions */
 int SQLITE_OK ; 
 int content_delete (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int deleteTerms (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int initPendingTerms (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int index_delete(fulltext_vtab *v, sqlite_int64 iRow){
  int rc = initPendingTerms(v, iRow);
  if( rc!=SQLITE_OK ) return rc;

  rc = deleteTerms(v, iRow);
  if( rc!=SQLITE_OK ) return rc;

  return content_delete(v, iRow);  /* execute an SQL DELETE */
}