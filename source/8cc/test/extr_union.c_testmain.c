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

/* Variables and functions */
 int /*<<< orphan*/  print (char*) ; 
 int /*<<< orphan*/  t1 () ; 
 int /*<<< orphan*/  t2 () ; 
 int /*<<< orphan*/  t3 () ; 
 int /*<<< orphan*/  test_sizeof () ; 

void testmain() {
    print("union");
    t1();
    t2();
    t3();
    test_sizeof();
}