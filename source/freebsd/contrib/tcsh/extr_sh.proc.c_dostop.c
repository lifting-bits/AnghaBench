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
struct command {int dummy; } ;
typedef  int /*<<< orphan*/  Char ;

/* Variables and functions */
 int /*<<< orphan*/  SIGSTOP ; 
 int /*<<< orphan*/  USE (struct command*) ; 
 int /*<<< orphan*/  pkill (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

void
dostop(Char **v, struct command *c)
{
    USE(c);
#ifdef BSDJOBS
    pkill(++v, SIGSTOP);
#endif /* BSDJOBS */
}