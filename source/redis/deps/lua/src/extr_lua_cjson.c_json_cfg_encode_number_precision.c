#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_3__ {int /*<<< orphan*/  encode_number_precision; } ;
typedef  TYPE_1__ json_config_t ;

/* Variables and functions */
 TYPE_1__* json_arg_init (int /*<<< orphan*/ *,int) ; 
 int json_integer_option (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int json_cfg_encode_number_precision(lua_State *l)
{
    json_config_t *cfg = json_arg_init(l, 1);

    return json_integer_option(l, 1, &cfg->encode_number_precision, 1, 14);
}