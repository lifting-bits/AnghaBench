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
typedef  int /*<<< orphan*/  Elf ;

/* Variables and functions */
 scalar_t__ _libelf_getshdrstrndx (int /*<<< orphan*/ *,size_t*) ; 

int
elf_getshstrndx(Elf *e, size_t *strndx)	/* Deprecated API. */
{
	return (_libelf_getshdrstrndx(e, strndx) >= 0);
}