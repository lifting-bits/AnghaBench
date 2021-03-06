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
struct TYPE_3__ {void* handle; } ;
typedef  int /*<<< orphan*/  GCtab ;
typedef  int /*<<< orphan*/  GCstr ;
typedef  TYPE_1__ CLibrary ;

/* Variables and functions */
 void* clib_loadlib (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* clib_new (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strdata (int /*<<< orphan*/ *) ; 

void lj_clib_load(lua_State *L, GCtab *mt, GCstr *name, int global)
{
  void *handle = clib_loadlib(L, strdata(name), global);
  CLibrary *cl = clib_new(L, mt);
  cl->handle = handle;
}