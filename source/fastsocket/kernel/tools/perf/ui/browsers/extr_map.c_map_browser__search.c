#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  target ;
struct symbol {int /*<<< orphan*/  rb_node; } ;
struct TYPE_2__ {int /*<<< orphan*/  top_idx; int /*<<< orphan*/  index; int /*<<< orphan*/ * top; } ;
struct map_browser {TYPE_1__ b; int /*<<< orphan*/  map; } ;

/* Variables and functions */
 struct symbol* map__find_symbol (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct symbol* map__find_symbol_by_name (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strtoull (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * symbol__browser_index (struct symbol*) ; 
 char tolower (char) ; 
 int ui_entry__read (char*,char*,int,int) ; 
 int /*<<< orphan*/  ui_helpline__fpush (char*,char*) ; 

__attribute__((used)) static int map_browser__search(struct map_browser *self)
{
	char target[512];
	struct symbol *sym;
	int err = ui_entry__read("Search by name/addr", target, sizeof(target), 40);

	if (err)
		return err;

	if (target[0] == '0' && tolower(target[1]) == 'x') {
		u64 addr = strtoull(target, NULL, 16);
		sym = map__find_symbol(self->map, addr, NULL);
	} else
		sym = map__find_symbol_by_name(self->map, target, NULL);

	if (sym != NULL) {
		u32 *idx = symbol__browser_index(sym);

		self->b.top = &sym->rb_node;
		self->b.index = self->b.top_idx = *idx;
	} else
		ui_helpline__fpush("%s not found!", target);

	return 0;
}