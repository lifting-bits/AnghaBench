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
struct fetch_negotiator {int /*<<< orphan*/  data; int /*<<< orphan*/ * known_common; } ;
struct commit {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SEEN ; 
 int /*<<< orphan*/  rev_list_push (int /*<<< orphan*/ ,struct commit*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void add_tip(struct fetch_negotiator *n, struct commit *c)
{
	n->known_common = NULL;
	rev_list_push(n->data, c, SEEN);
}