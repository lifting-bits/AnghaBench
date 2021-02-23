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
typedef  int /*<<< orphan*/  wchar_t ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int CreateDirectory (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetLastError () ; 
 size_t MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 scalar_t__ malloc (int) ; 

int wceex_mkdir(const char *filename)
{
    int res;    
    size_t len;
    wchar_t *widestr;

    /* Covert filename buffer to Unicode. */
    len = MultiByteToWideChar (CP_ACP, 0, filename, -1, NULL, 0) ;
	widestr  = (wchar_t*)malloc(sizeof(wchar_t) * len);

    MultiByteToWideChar( CP_ACP, 0, filename, -1, widestr, len);
	
    /* Delete file using Win32 CE API call */
    res = CreateDirectory(widestr, NULL);
	
    /* Free wide-char string */
    free(widestr);

    if (res)
	    return 0; /* success */
    else
    {
        errno = GetLastError();
        return -1;
    }
}