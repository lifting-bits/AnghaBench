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
struct tcp_heuristics_head {int /*<<< orphan*/  thh_mtx; } ;

/* Variables and functions */
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void tcp_heuristic_unlock(struct tcp_heuristics_head *head)
{
	lck_mtx_unlock(&head->thh_mtx);
}