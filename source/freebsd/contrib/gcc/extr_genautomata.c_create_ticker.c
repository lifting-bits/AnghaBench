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
struct TYPE_3__ {scalar_t__ incremented_off_time; int /*<<< orphan*/  modified_creation_time; } ;
typedef  TYPE_1__ ticker_t ;

/* Variables and functions */
 int /*<<< orphan*/  get_run_time () ; 

__attribute__((used)) static ticker_t
create_ticker (void)
{
  ticker_t ticker;

  ticker.modified_creation_time = get_run_time ();
  ticker.incremented_off_time = 0;
  return ticker;
}