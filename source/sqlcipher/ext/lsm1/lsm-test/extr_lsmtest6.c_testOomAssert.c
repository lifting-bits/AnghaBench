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
struct TYPE_3__ {int rc; } ;
typedef  TYPE_1__ OomTest ;

/* Variables and functions */
 int /*<<< orphan*/  test_failed () ; 

__attribute__((used)) static void testOomAssert(OomTest *p, int bVal){
  if( bVal==0 ){
    test_failed();
    p->rc = 1;
  }
}