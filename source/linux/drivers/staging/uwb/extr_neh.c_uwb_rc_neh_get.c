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
struct uwb_rc_neh {int /*<<< orphan*/  kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void uwb_rc_neh_get(struct uwb_rc_neh *neh)
{
	kref_get(&neh->kref);
}