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
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 scalar_t__ IsBadWritePtr (char*,int) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  ok (int,char*,scalar_t__) ; 

__attribute__((used)) static void test_IsBadWritePtr(void)
{
    BOOL ret;
    void *ptr = (void *)0xdeadbeef;
    char stackval;

    ret = IsBadWritePtr(NULL, 0);
    ok(ret == FALSE, "Expected IsBadWritePtr to return FALSE, got %d\n", ret);

    ret = IsBadWritePtr(NULL, 1);
    ok(ret == TRUE, "Expected IsBadWritePtr to return TRUE, got %d\n", ret);

    ret = IsBadWritePtr(ptr, 0);
    ok(ret == FALSE, "Expected IsBadWritePtr to return FALSE, got %d\n", ret);

    ret = IsBadWritePtr(ptr, 1);
    ok(ret == TRUE, "Expected IsBadWritePtr to return TRUE, got %d\n", ret);

    ret = IsBadWritePtr(&stackval, 0);
    ok(ret == FALSE, "Expected IsBadWritePtr to return FALSE, got %d\n", ret);

    ret = IsBadWritePtr(&stackval, sizeof(char));
    ok(ret == FALSE, "Expected IsBadWritePtr to return FALSE, got %d\n", ret);
}