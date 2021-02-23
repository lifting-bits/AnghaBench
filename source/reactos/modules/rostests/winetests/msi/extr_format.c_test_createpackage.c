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
typedef  scalar_t__ UINT ;
typedef  int /*<<< orphan*/  MSIHANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  DeleteFileA (int /*<<< orphan*/ ) ; 
 scalar_t__ ERROR_INSTALL_PACKAGE_REJECTED ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ MsiCloseHandle (int /*<<< orphan*/ ) ; 
 scalar_t__ helper_createpackage (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msifile ; 
 int /*<<< orphan*/  ok (int,char*,scalar_t__) ; 
 int /*<<< orphan*/  skip (char*) ; 

__attribute__((used)) static void test_createpackage(void)
{
    MSIHANDLE hPackage = 0;
    UINT res;

    res = helper_createpackage( msifile, &hPackage );
    if (res == ERROR_INSTALL_PACKAGE_REJECTED)
    {
        skip("Not enough rights to perform tests\n");
        return;
    }
    ok( res == ERROR_SUCCESS, "Failed to create package %u\n", res );

    res = MsiCloseHandle( hPackage );
    ok( res == ERROR_SUCCESS , "Failed to close package %u\n", res );

    DeleteFileA( msifile );
}