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
typedef  int /*<<< orphan*/  ngx_log_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  lua_createtable (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lua_pushcfunction (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_setfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  ngx_http_lua_uthread_kill ; 
 int /*<<< orphan*/  ngx_http_lua_uthread_spawn ; 
 int /*<<< orphan*/  ngx_http_lua_uthread_wait ; 

void
ngx_http_lua_inject_uthread_api(ngx_log_t *log, lua_State *L)
{
    /* new thread table */
    lua_createtable(L, 0 /* narr */, 3 /* nrec */);

    lua_pushcfunction(L, ngx_http_lua_uthread_spawn);
    lua_setfield(L, -2, "spawn");

    lua_pushcfunction(L, ngx_http_lua_uthread_wait);
    lua_setfield(L, -2, "wait");

    lua_pushcfunction(L, ngx_http_lua_uthread_kill);
    lua_setfield(L, -2, "kill");

    lua_setfield(L, -2, "thread");
}