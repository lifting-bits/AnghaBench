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
struct mbq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __mbq_purge (struct mbq*,int) ; 

void mbq_safe_purge(struct mbq *q)
{
    __mbq_purge(q, 1);
}