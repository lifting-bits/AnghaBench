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
struct Smain {int argc; char** argv; } ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  Proto ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ IS (char*) ; 
 int LUA_ERR_CC_INTOVERFLOW ; 
 int LUA_ERR_CC_NOTINTEGER ; 
 int /*<<< orphan*/  address ; 
 int /*<<< orphan*/  cannot (char*) ; 
 int /*<<< orphan*/ * combine (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int dumpToFlashImage (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ dumping ; 
 char const* execute ; 
 int /*<<< orphan*/  fatal (char*) ; 
 scalar_t__ fclose (int /*<<< orphan*/ *) ; 
 scalar_t__ ferror (int /*<<< orphan*/ *) ; 
 scalar_t__ flash ; 
 int /*<<< orphan*/ * fopen (int /*<<< orphan*/ *,char*) ; 
 int listing ; 
 int /*<<< orphan*/  lookup ; 
 scalar_t__ luaL_loadfile (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  luaL_openlibs (int /*<<< orphan*/ *) ; 
 int luaU_dump_crosscompile (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaU_print (int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  lua_checkstack (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_isfunction (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_lock (int /*<<< orphan*/ *) ; 
 scalar_t__ lua_pcall (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushstring (int /*<<< orphan*/ *,char const*) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_touserdata (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  maxSize ; 
 int /*<<< orphan*/ * output ; 
 int /*<<< orphan*/ * stdout ; 
 int /*<<< orphan*/  stripping ; 
 int /*<<< orphan*/  target ; 
 int /*<<< orphan*/  writer ; 

__attribute__((used)) static int pmain(lua_State* L)
{
 struct Smain* s = (struct Smain*)lua_touserdata(L, 1);
 int argc=s->argc;
 char** argv=s->argv;
 const Proto* f;
 int i;
 if (!lua_checkstack(L,argc)) fatal("too many input files");
 if (execute)
 {
  if (luaL_loadfile(L,execute)!=0) fatal(lua_tostring(L,-1));
  luaL_openlibs(L);
  lua_pushstring(L, execute);
  if (lua_pcall(L, 1, 1, 0)) fatal(lua_tostring(L,-1));
  if (!lua_isfunction(L, -1))
  {
   lua_pop(L,1);
   if(argc == 0) return 0;
   execute = NULL;
  }
 }
 for (i=0; i<argc; i++)
 {
  const char* filename=IS("-") ? NULL : argv[i];
  if (luaL_loadfile(L,filename)!=0) fatal(lua_tostring(L,-1));
 }
 f=combine(L,argc + (execute ? 1: 0), lookup);
 if (listing) luaU_print(f,listing>1);
 if (dumping)
 {
  int result;
  FILE* D= (output==NULL) ? stdout : fopen(output,"wb");
  if (D==NULL) cannot("open");
  lua_lock(L);
  if (flash)
  {
    result=dumpToFlashImage(L,f,writer, D, stripping, address, maxSize);
  } else
  {
    result=luaU_dump_crosscompile(L,f,writer,D,stripping,target);
  }
  lua_unlock(L);
  if (result==LUA_ERR_CC_INTOVERFLOW) fatal("value too big or small for target integer type");
  if (result==LUA_ERR_CC_NOTINTEGER) fatal("target lua_Number is integral but fractional value found");
  if (ferror(D)) cannot("write");
  if (fclose(D)) cannot("close");
 }
 return 0;
}