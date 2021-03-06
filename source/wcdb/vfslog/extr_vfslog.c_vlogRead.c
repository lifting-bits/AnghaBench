#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zStr ;
typedef  int sqlite_int64 ;
typedef  scalar_t__ sqlite3_uint64 ;
typedef  int /*<<< orphan*/  sqlite3_file ;
struct TYPE_6__ {TYPE_3__* pLog; TYPE_4__* pReal; } ;
typedef  TYPE_2__ VLogFile ;
struct TYPE_8__ {TYPE_1__* pMethods; } ;
struct TYPE_7__ {int lastReadOfs; int /*<<< orphan*/  gzMutex; scalar_t__ zFilename; } ;
struct TYPE_5__ {int (* xRead ) (TYPE_4__*,void*,int,int) ;} ;

/* Variables and functions */
 int SQLITE_OK ; 
 int /*<<< orphan*/  VLOG_OP_CHNGCTR_READ ; 
 int /*<<< orphan*/  VLOG_OP_READ ; 
 unsigned int bigToNative (unsigned char*) ; 
 int /*<<< orphan*/  sqlite3_mutex_enter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_mutex_leave (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_snprintf (int,char*,char*,unsigned int) ; 
 int stub1 (TYPE_4__*,void*,int,int) ; 
 int /*<<< orphan*/  vlogLogPrint (TYPE_3__*,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int,int,char*,int) ; 
 int /*<<< orphan*/  vlogSignature (void*,int,char*) ; 
 scalar_t__ vlog_time () ; 

__attribute__((used)) static int
vlogRead(sqlite3_file *pFile, void *zBuf, int iAmt, sqlite_int64 iOfst)
{
    int rc;
    sqlite3_uint64 tStart, tElapse;
    VLogFile *p = (VLogFile *) pFile;

    tStart = vlog_time();
    rc = p->pReal->pMethods->xRead(p->pReal, zBuf, iAmt, iOfst);
    tElapse = vlog_time() - tStart;

    if (rc == SQLITE_OK && p->pLog && p->pLog->zFilename && iOfst <= 24 &&
        iOfst + iAmt >= 28) {

        unsigned char *x = ((unsigned char *) zBuf) + (24 - iOfst);
        unsigned iCtr, nFree = -1;
        char *zFree = 0;
        char zStr[12];
        iCtr = bigToNative(x);
        if (iOfst + iAmt >= 40) {
            zFree = zStr;
            sqlite3_snprintf(sizeof(zStr), zStr, "%d", bigToNative(x + 8));
            nFree = bigToNative(x + 12);
        }

        /* XXX: Values are meaningful only for plain-text databases */
        vlogLogPrint(p->pLog, tStart, tElapse, VLOG_OP_CHNGCTR_READ, iCtr,
                     nFree, zFree, 0);
    } else {
        char zSig[40];
        if (rc == SQLITE_OK) {
            vlogSignature(zBuf, iAmt, zSig);
        } else {
            zSig[0] = 0;
        }

        /* Record last read position */
        sqlite3_mutex_enter(p->pLog->gzMutex);
        p->pLog->lastReadOfs = iOfst;
        sqlite3_mutex_leave(p->pLog->gzMutex);

        vlogLogPrint(p->pLog, tStart, tElapse, VLOG_OP_READ, iAmt, iOfst, zSig,
                     rc);
    }
    return rc;
}