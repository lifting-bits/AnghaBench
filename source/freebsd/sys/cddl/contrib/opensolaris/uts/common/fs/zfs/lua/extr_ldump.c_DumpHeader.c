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
typedef  int /*<<< orphan*/  lu_byte ;
typedef  int /*<<< orphan*/  DumpState ;

/* Variables and functions */
 int /*<<< orphan*/  DumpBlock (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int LUAC_HEADERSIZE ; 
 int /*<<< orphan*/  luaU_header (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void DumpHeader(DumpState* D)
{
 lu_byte h[LUAC_HEADERSIZE];
 luaU_header(h);
 DumpBlock(h,LUAC_HEADERSIZE,D);
}