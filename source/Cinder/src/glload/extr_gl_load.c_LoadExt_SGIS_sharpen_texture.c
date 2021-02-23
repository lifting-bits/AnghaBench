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
typedef  scalar_t__ PFNGLSHARPENTEXFUNCSGISPROC ;
typedef  scalar_t__ PFNGLGETSHARPENTEXFUNCSGISPROC ;

/* Variables and functions */
 scalar_t__ IntGetProcAddress (char*) ; 
 scalar_t__ _funcptr_glGetSharpenTexFuncSGIS ; 
 scalar_t__ _funcptr_glSharpenTexFuncSGIS ; 

__attribute__((used)) static int LoadExt_SGIS_sharpen_texture()
{
	int numFailed = 0;
	_funcptr_glGetSharpenTexFuncSGIS = (PFNGLGETSHARPENTEXFUNCSGISPROC)IntGetProcAddress("glGetSharpenTexFuncSGIS");
	if(!_funcptr_glGetSharpenTexFuncSGIS) ++numFailed;
	_funcptr_glSharpenTexFuncSGIS = (PFNGLSHARPENTEXFUNCSGISPROC)IntGetProcAddress("glSharpenTexFuncSGIS");
	if(!_funcptr_glSharpenTexFuncSGIS) ++numFailed;
	return numFailed;
}