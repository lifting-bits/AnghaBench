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
struct ieee80211_ageq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ieee80211_ageq_mfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_ageq_remove (struct ieee80211_ageq*,int /*<<< orphan*/ *) ; 

void
ieee80211_ageq_drain(struct ieee80211_ageq *aq)
{
	ieee80211_ageq_mfree(ieee80211_ageq_remove(aq, NULL));
}