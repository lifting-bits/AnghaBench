#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__* vec3_t ;
struct TYPE_11__ {int /*<<< orphan*/  client; scalar_t__* origin; } ;
typedef  TYPE_1__ bot_movestate_t ;
struct TYPE_12__ {int /*<<< orphan*/  movedir; } ;
typedef  TYPE_2__ bot_moveresult_t ;
struct TYPE_13__ {scalar_t__* start; } ;
typedef  TYPE_3__ aas_reachability_t ;

/* Variables and functions */
 int /*<<< orphan*/  BotCheckBlocked (TYPE_1__*,scalar_t__*,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  EA_Move (int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int /*<<< orphan*/  VectorCopy (scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bot_moveresult_t_cleared (TYPE_2__) ; 
 int /*<<< orphan*/  qtrue ; 
 TYPE_2__ result ; 

bot_moveresult_t BotTravel_JumpPad(bot_movestate_t *ms, aas_reachability_t *reach)
{
	vec3_t hordir;
	bot_moveresult_t_cleared( result );

	//first walk straight to the reachability start
	hordir[0] = reach->start[0] - ms->origin[0];
	hordir[1] = reach->start[1] - ms->origin[1];
	hordir[2] = 0;
	//
	BotCheckBlocked(ms, hordir, qtrue, &result);
	//elemantary action move in direction
	EA_Move(ms->client, hordir, 400);
	VectorCopy(hordir, result.movedir);
	//
	return result;
}