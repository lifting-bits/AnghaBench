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
struct search_gather_extra {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  zzfree (void*,int) ; 

int search_free_gather_extra (void *E) {
  zzfree (E, sizeof (struct search_gather_extra));
  return 0;
}