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
struct upgt_vap {int dummy; } ;
struct ieee80211vap {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_80211_VAP ; 
 struct upgt_vap* UPGT_VAP (struct ieee80211vap*) ; 
 int /*<<< orphan*/  free (struct upgt_vap*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_vap_detach (struct ieee80211vap*) ; 

__attribute__((used)) static void
upgt_vap_delete(struct ieee80211vap *vap)
{
	struct upgt_vap *uvp = UPGT_VAP(vap);

	ieee80211_vap_detach(vap);
	free(uvp, M_80211_VAP);
}