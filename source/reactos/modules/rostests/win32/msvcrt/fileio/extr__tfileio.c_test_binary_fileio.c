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
typedef  int /*<<< orphan*/  TCHAR ;

/* Variables and functions */
 int /*<<< orphan*/  _T (char*) ; 
 int check_file_size (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int create_test_file (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int test_binary_fileio(TCHAR* file_name, TCHAR* file_data, int tsize, int bsize)
{
    int result = 0;

    result = create_test_file(file_name, _T("wb"), _T("rb"), file_data);
    result = check_file_size(file_name, _T("r"), tsize);
    result = check_file_size(file_name, _T("rb"), bsize);
    return result;
}