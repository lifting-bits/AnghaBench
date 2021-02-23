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
typedef  int LONG ;

/* Variables and functions */
 int InterlockedExchangeAdd (int*,int) ; 
 int /*<<< orphan*/  ok (int,char*,int,int) ; 

__attribute__((used)) static void test_InterlockedExchangeAdd(void)
{
    LONG dest, res;

    dest = 0;
    res = InterlockedExchangeAdd( &dest, 1 );
    ok( res == 0 && dest == 1,
        "Expected 0 and 1, got %ld and %ld", res, dest );

    dest = 1;
    res = InterlockedExchangeAdd( &dest, 2 );
    ok( res == 1 && dest == 3,
        "Expected 1 and 3, got %ld and %ld", res, dest );

    dest = 1;
    res = InterlockedExchangeAdd( &dest, -1 );
    ok( res == 1 && dest == 0,
        "Expected 1 and 0, got %ld and %ld", res, dest );
}