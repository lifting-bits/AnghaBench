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
struct cstate {int /*<<< orphan*/  lookahead; } ;

/* Variables and functions */
 int /*<<< orphan*/  lex (struct cstate*) ; 

__attribute__((used)) static void next(struct cstate *g)
{
	g->lookahead = lex(g);
}