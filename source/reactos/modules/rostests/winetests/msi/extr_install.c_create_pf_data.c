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
typedef  char* LPCSTR ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CreateDirectoryA (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  PROG_FILES_DIR ; 
 int /*<<< orphan*/  create_file_data (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  lstrcatA (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lstrcpyA (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void create_pf_data(LPCSTR file, LPCSTR data, BOOL is_file)
{
    CHAR path[MAX_PATH];

    lstrcpyA(path, PROG_FILES_DIR);
    lstrcatA(path, "\\");
    lstrcatA(path, file);

    if (is_file)
        create_file_data(path, data, 500);
    else
        CreateDirectoryA(path, NULL);
}