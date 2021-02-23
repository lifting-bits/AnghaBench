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
typedef  int /*<<< orphan*/  u_int32_t ;
struct au_info {int /*<<< orphan*/ * sh; int /*<<< orphan*/ * st; } ;

/* Variables and functions */
 int /*<<< orphan*/  bus_space_write_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_space_write_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_space_write_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
au_wr(struct au_info *au, int mapno, int regno, u_int32_t data, int size)
{
	switch(size) {
	case 1:
		bus_space_write_1(au->st[mapno], au->sh[mapno], regno, data);
		break;
	case 2:
		bus_space_write_2(au->st[mapno], au->sh[mapno], regno, data);
		break;
	case 4:
		bus_space_write_4(au->st[mapno], au->sh[mapno], regno, data);
		break;
	}
}