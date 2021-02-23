#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct analog_demod_ops {int /*<<< orphan*/  (* standby ) (TYPE_2__*) ;} ;
struct TYPE_3__ {struct analog_demod_ops analog_ops; } ;
struct TYPE_4__ {TYPE_1__ ops; } ;
struct tuner {TYPE_2__ fe; int /*<<< orphan*/  standby; } ;
struct i2c_client {int dummy; } ;
typedef  int /*<<< orphan*/  pm_message_t ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 
 struct tuner* to_tuner (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tuner_dbg (char*) ; 

__attribute__((used)) static int tuner_suspend(struct i2c_client *c, pm_message_t state)
{
	struct tuner *t = to_tuner(i2c_get_clientdata(c));
	struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;

	tuner_dbg("suspend\n");

	if (!t->standby && analog_ops->standby)
		analog_ops->standby(&t->fe);

	return 0;
}