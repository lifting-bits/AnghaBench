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
typedef  void* time_t ;
struct _tfinddata_t {int /*<<< orphan*/  name; scalar_t__ size; void* time_write; void* time_access; void* time_create; int /*<<< orphan*/  attrib; } ;
typedef  int __int64 ;
struct TYPE_3__ {int /*<<< orphan*/  cFileName; scalar_t__ nFileSizeLow; scalar_t__ nFileSizeHigh; int /*<<< orphan*/  ftLastWriteTime; int /*<<< orphan*/  ftLastAccessTime; int /*<<< orphan*/  ftCreationTime; int /*<<< orphan*/  dwFileAttributes; } ;
typedef  TYPE_1__ WIN32_FIND_DATA ;
typedef  int /*<<< orphan*/  HANDLE ;

/* Variables and functions */
 scalar_t__ FileTimeToUnixTime (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FindNextFile (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  MAX_PATH ; 
 int /*<<< orphan*/  _dosmaperr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _tcsncpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int _tfindnext(intptr_t handle, struct _tfinddata_t* result)
{
    WIN32_FIND_DATA FindFileData;

    if (!FindNextFile((HANDLE)handle, &FindFileData)) {
    	_dosmaperr(GetLastError());
        return -1;
	}

    result->attrib = FindFileData.dwFileAttributes;
    result->time_create = (time_t)FileTimeToUnixTime(&FindFileData.ftCreationTime,NULL);
    result->time_access = (time_t)FileTimeToUnixTime(&FindFileData.ftLastAccessTime,NULL);
    result->time_write = (time_t)FileTimeToUnixTime(&FindFileData.ftLastWriteTime,NULL);
    result->size = (((__int64)FindFileData.nFileSizeHigh)<<32) + FindFileData.nFileSizeLow;
    _tcsncpy(result->name,FindFileData.cFileName, MAX_PATH);

    return 0;
}