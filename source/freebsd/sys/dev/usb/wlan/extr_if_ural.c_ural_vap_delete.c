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
struct ural_vap {int /*<<< orphan*/  ratectl_task; int /*<<< orphan*/  ratectl_ch; } ;
struct ieee80211vap {struct ieee80211com* iv_ic; } ;
struct ieee80211com {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_80211_VAP ; 
 struct ural_vap* URAL_VAP (struct ieee80211vap*) ; 
 int /*<<< orphan*/  free (struct ural_vap*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_draintask (struct ieee80211com*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ieee80211_ratectl_deinit (struct ieee80211vap*) ; 
 int /*<<< orphan*/  ieee80211_vap_detach (struct ieee80211vap*) ; 
 int /*<<< orphan*/  usb_callout_drain (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ural_vap_delete(struct ieee80211vap *vap)
{
	struct ural_vap *uvp = URAL_VAP(vap);
	struct ieee80211com *ic = vap->iv_ic;

	usb_callout_drain(&uvp->ratectl_ch);
	ieee80211_draintask(ic, &uvp->ratectl_task);
	ieee80211_ratectl_deinit(vap);
	ieee80211_vap_detach(vap);
	free(uvp, M_80211_VAP);
}