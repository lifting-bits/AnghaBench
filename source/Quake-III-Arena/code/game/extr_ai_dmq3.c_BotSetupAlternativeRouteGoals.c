#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int /*<<< orphan*/  areanum; int /*<<< orphan*/  origin; } ;
struct TYPE_11__ {int /*<<< orphan*/  areanum; int /*<<< orphan*/  origin; } ;
struct TYPE_10__ {int /*<<< orphan*/  areanum; int /*<<< orphan*/  origin; } ;
struct TYPE_9__ {int /*<<< orphan*/  areanum; int /*<<< orphan*/  origin; } ;
struct TYPE_8__ {scalar_t__ areanum; int /*<<< orphan*/  origin; } ;

/* Variables and functions */
 int ALTROUTEGOAL_CLUSTERPORTALS ; 
 int ALTROUTEGOAL_VIEWPORTALS ; 
 int /*<<< orphan*/  BotAI_Print (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ GT_1FCTF ; 
 scalar_t__ GT_CTF ; 
 scalar_t__ GT_HARVESTER ; 
 scalar_t__ GT_OBELISK ; 
 int /*<<< orphan*/  MAX_ALTROUTEGOALS ; 
 int /*<<< orphan*/  PRT_WARNING ; 
 int /*<<< orphan*/  TFL_DEFAULT ; 
 scalar_t__ altroutegoals_setup ; 
 int /*<<< orphan*/  blue_altroutegoals ; 
 void* blue_numaltroutegoals ; 
 TYPE_7__ blueobelisk ; 
 TYPE_6__ ctf_blueflag ; 
 TYPE_1__ ctf_neutralflag ; 
 TYPE_4__ ctf_redflag ; 
 scalar_t__ gametype ; 
 TYPE_1__ neutralobelisk ; 
 scalar_t__ qtrue ; 
 int /*<<< orphan*/  red_altroutegoals ; 
 void* red_numaltroutegoals ; 
 TYPE_2__ redobelisk ; 
 void* trap_AAS_AlternativeRouteGoals (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ trap_BotGetLevelItemGoal (int,char*,TYPE_1__*) ; 

void BotSetupAlternativeRouteGoals(void) {

	if (altroutegoals_setup)
		return;
#ifdef MISSIONPACK
	if (gametype == GT_CTF) {
		if (trap_BotGetLevelItemGoal(-1, "Neutral Flag", &ctf_neutralflag) < 0)
			BotAI_Print(PRT_WARNING, "no alt routes without Neutral Flag\n");
		if (ctf_neutralflag.areanum) {
			//
			red_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
										ctf_neutralflag.origin, ctf_neutralflag.areanum,
										ctf_redflag.origin, ctf_redflag.areanum, TFL_DEFAULT,
										red_altroutegoals, MAX_ALTROUTEGOALS,
										ALTROUTEGOAL_CLUSTERPORTALS|
										ALTROUTEGOAL_VIEWPORTALS);
			blue_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
										ctf_neutralflag.origin, ctf_neutralflag.areanum,
										ctf_blueflag.origin, ctf_blueflag.areanum, TFL_DEFAULT,
										blue_altroutegoals, MAX_ALTROUTEGOALS,
										ALTROUTEGOAL_CLUSTERPORTALS|
										ALTROUTEGOAL_VIEWPORTALS);
		}
	}
	else if (gametype == GT_1FCTF) {
		//
		red_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
									ctf_neutralflag.origin, ctf_neutralflag.areanum,
									ctf_redflag.origin, ctf_redflag.areanum, TFL_DEFAULT,
									red_altroutegoals, MAX_ALTROUTEGOALS,
									ALTROUTEGOAL_CLUSTERPORTALS|
									ALTROUTEGOAL_VIEWPORTALS);
		blue_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
									ctf_neutralflag.origin, ctf_neutralflag.areanum,
									ctf_blueflag.origin, ctf_blueflag.areanum, TFL_DEFAULT,
									blue_altroutegoals, MAX_ALTROUTEGOALS,
									ALTROUTEGOAL_CLUSTERPORTALS|
									ALTROUTEGOAL_VIEWPORTALS);
	}
	else if (gametype == GT_OBELISK) {
		if (trap_BotGetLevelItemGoal(-1, "Neutral Obelisk", &neutralobelisk) < 0)
			BotAI_Print(PRT_WARNING, "Harvester without neutral obelisk\n");
		//
		red_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
									neutralobelisk.origin, neutralobelisk.areanum,
									redobelisk.origin, redobelisk.areanum, TFL_DEFAULT,
									red_altroutegoals, MAX_ALTROUTEGOALS,
									ALTROUTEGOAL_CLUSTERPORTALS|
									ALTROUTEGOAL_VIEWPORTALS);
		blue_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
									neutralobelisk.origin, neutralobelisk.areanum,
									blueobelisk.origin, blueobelisk.areanum, TFL_DEFAULT,
									blue_altroutegoals, MAX_ALTROUTEGOALS,
									ALTROUTEGOAL_CLUSTERPORTALS|
									ALTROUTEGOAL_VIEWPORTALS);
	}
	else if (gametype == GT_HARVESTER) {
		//
		red_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
									neutralobelisk.origin, neutralobelisk.areanum,
									redobelisk.origin, redobelisk.areanum, TFL_DEFAULT,
									red_altroutegoals, MAX_ALTROUTEGOALS,
									ALTROUTEGOAL_CLUSTERPORTALS|
									ALTROUTEGOAL_VIEWPORTALS);
		blue_numaltroutegoals = trap_AAS_AlternativeRouteGoals(
									neutralobelisk.origin, neutralobelisk.areanum,
									blueobelisk.origin, blueobelisk.areanum, TFL_DEFAULT,
									blue_altroutegoals, MAX_ALTROUTEGOALS,
									ALTROUTEGOAL_CLUSTERPORTALS|
									ALTROUTEGOAL_VIEWPORTALS);
	}
#endif
	altroutegoals_setup = qtrue;
}