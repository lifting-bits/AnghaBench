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
 int /*<<< orphan*/  ASSERT (int) ; 
 int NUM_ITERATIONS ; 
 int /*<<< orphan*/ * titles ; 
 scalar_t__ uv_set_process_title (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void setter_thread_body(void* arg) {
  int i;

  for (i = 0; i < NUM_ITERATIONS; i++) {
    ASSERT(0 == uv_set_process_title(titles[0]));
    ASSERT(0 == uv_set_process_title(titles[1]));
    ASSERT(0 == uv_set_process_title(titles[2]));
    ASSERT(0 == uv_set_process_title(titles[3]));
  }
}