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
struct timer {int dummy; } ;
typedef  scalar_t__ gpointer ;

/* Variables and functions */
 int /*<<< orphan*/  uiprivFree (struct timer*) ; 

__attribute__((used)) static void uninitTimer(gpointer key, gpointer value, gpointer data)
{
	uiprivFree((struct timer *) key);
}