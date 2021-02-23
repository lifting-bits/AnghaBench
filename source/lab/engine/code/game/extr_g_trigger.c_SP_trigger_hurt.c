#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int damage; int spawnflags; int /*<<< orphan*/  use; int /*<<< orphan*/  touch; int /*<<< orphan*/  noise_index; } ;
typedef  TYPE_1__ gentity_t ;

/* Variables and functions */
 int /*<<< orphan*/  G_SoundIndex (char*) ; 
 int /*<<< orphan*/  InitTrigger (TYPE_1__*) ; 
 int /*<<< orphan*/  hurt_touch ; 
 int /*<<< orphan*/  hurt_use ; 
 int /*<<< orphan*/  trap_LinkEntity (TYPE_1__*) ; 
 int /*<<< orphan*/  trap_UnlinkEntity (TYPE_1__*) ; 

void SP_trigger_hurt( gentity_t *self ) {
	InitTrigger (self);

	self->noise_index = G_SoundIndex( "sound/world/electro.wav" );
	self->touch = hurt_touch;

	if ( !self->damage ) {
		self->damage = 5;
	}

	self->use = hurt_use;

	// link in to the world if starting active
	if ( self->spawnflags & 1 ) {
		trap_UnlinkEntity (self);
	}
	else {
		trap_LinkEntity (self);
	}
}