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
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  lua_pushfstring (int /*<<< orphan*/ *,char*,char const*,char const*,char const*) ; 
 int /*<<< orphan*/  lua_remove (int /*<<< orphan*/ *,int) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 
 char* strerror (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int errfile(lua_State*L,const char*what,int fnameindex){
const char*serr=strerror(errno);
const char*filename=lua_tostring(L,fnameindex)+1;
lua_pushfstring(L,"cannot %s %s: %s",what,filename,serr);
lua_remove(L,fnameindex);
return(5+1);
}