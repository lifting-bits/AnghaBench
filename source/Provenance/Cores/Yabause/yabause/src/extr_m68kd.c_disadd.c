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
typedef  scalar_t__ u32 ;
typedef  int u16 ;

/* Variables and functions */
 int /*<<< orphan*/  seteafieldstr (scalar_t__,int,int*,char*) ; 
 int /*<<< orphan*/  setsizestr2 (int,char*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 

__attribute__((used)) static int disadd(u32 addr, u16 op, char *outstring)
{
   int size=2;

   outstring += sprintf(outstring, "add");
   outstring += setsizestr2(op >> 6, outstring);
   outstring += sprintf(outstring, "  ");

   if (op & 0x100)
   {
      // Dn, <ea>
      outstring += sprintf(outstring, "d%d, ", (op >> 9) & 7);
      seteafieldstr(addr+size, op, &size, outstring);
   }
   else
   {
      // <ea>, Dn
      outstring += seteafieldstr(addr+size, op, &size, outstring);
      sprintf(outstring, ", d%d", (op >> 9) & 7);
   }

   return size;
}