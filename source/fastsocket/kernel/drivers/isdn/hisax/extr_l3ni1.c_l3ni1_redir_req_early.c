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
typedef  int /*<<< orphan*/  u_char ;
struct l3_process {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  l3ni1_proceed_req (struct l3_process*,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  l3ni1_redir_req (struct l3_process*,int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static void l3ni1_redir_req_early(struct l3_process *pc, u_char pr, void *arg)
{
  l3ni1_proceed_req(pc,pr,arg);
  l3ni1_redir_req(pc,pr,arg);
}