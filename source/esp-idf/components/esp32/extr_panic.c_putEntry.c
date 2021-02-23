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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  panicPutHex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panicPutStr (char*) ; 

__attribute__((used)) static void putEntry(uint32_t pc, uint32_t sp)
{
    panicPutStr(" 0x");
    panicPutHex(pc);
    panicPutStr(":0x");
    panicPutHex(sp);
}