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
 scalar_t__ CC ; 
 scalar_t__* Clusters ; 
 int /*<<< orphan*/  cluster_precise_cron () ; 
 int max_cluster ; 

void precise_cron (void) {
  int i;
  for (i = 0; i < max_cluster; i++) if (Clusters[i]) {
    CC = Clusters[i];
    cluster_precise_cron ();
  }
}