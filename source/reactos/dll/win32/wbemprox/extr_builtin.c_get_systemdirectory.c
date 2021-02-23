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
typedef  int /*<<< orphan*/  WCHAR ;

/* Variables and functions */
 int /*<<< orphan*/  GetSystemDirectoryW (int /*<<< orphan*/ *,int) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  Wow64DisableWow64FsRedirection (void**) ; 
 int /*<<< orphan*/  Wow64RevertWow64FsRedirection (void*) ; 
 int /*<<< orphan*/ * heap_alloc (int) ; 

__attribute__((used)) static WCHAR *get_systemdirectory(void)
{
    void *redir;
    WCHAR *ret;

    if (!(ret = heap_alloc( MAX_PATH * sizeof(WCHAR) ))) return NULL;
    Wow64DisableWow64FsRedirection( &redir );
    GetSystemDirectoryW( ret, MAX_PATH );
    Wow64RevertWow64FsRedirection( redir );
    return ret;
}