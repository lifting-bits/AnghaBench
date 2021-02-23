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
struct stlibrd {scalar_t__ iobase; } ;

/* Variables and functions */
 scalar_t__ ECP_ATCONFR ; 
 int /*<<< orphan*/  ECP_ATDISABLE ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void stli_ecpdisable(struct stlibrd *brdp)
{	
	outb(ECP_ATDISABLE, (brdp->iobase + ECP_ATCONFR));
}