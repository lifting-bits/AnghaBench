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
struct au_info {int dummy; } ;
struct au_chinfo {scalar_t__ dir; struct au_info* parent; } ;
typedef  int /*<<< orphan*/  kobj_t ;

/* Variables and functions */
 int AU_BUFFSIZE ; 
 int /*<<< orphan*/  AU_REG_UNK2 ; 
 scalar_t__ PCMDIR_PLAY ; 
 int au_rd (struct au_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
auchan_getptr(kobj_t obj, void *data)
{
	struct au_chinfo *ch = data;
	struct au_info *au = ch->parent;
	if (ch->dir == PCMDIR_PLAY) {
		return au_rd(au, 0, AU_REG_UNK2, 4) & (AU_BUFFSIZE-1);
	} else {
		return 0;
	}
}