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
typedef  int /*<<< orphan*/  p_udp ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  auxiliar_checkgroup (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int meth_dirty(lua_State *L) {
    p_udp udp = (p_udp) auxiliar_checkgroup(L, "udp{any}", 1);
    (void) udp;
    lua_pushboolean(L, 0);
    return 1;
}