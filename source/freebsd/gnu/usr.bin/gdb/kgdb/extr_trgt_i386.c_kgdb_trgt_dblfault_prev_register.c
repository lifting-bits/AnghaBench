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
struct kgdb_tss_cache {scalar_t__ tss; } ;
struct frame_info {int dummy; } ;
typedef  enum lval_type { ____Placeholder_lval_type } lval_type ;
typedef  scalar_t__ CORE_ADDR ;

/* Variables and functions */
 int I386_EAX_REGNUM ; 
 int I386_FS_REGNUM ; 
 int MAX_REGISTER_SIZE ; 
 int /*<<< orphan*/  current_gdbarch ; 
 struct kgdb_tss_cache* kgdb_trgt_tss_cache (struct frame_info*,void**) ; 
 int* kgdb_trgt_tss_offset ; 
 int lval_memory ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 int not_lval ; 
 int register_size (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  target_read_memory (scalar_t__,void*,int) ; 

__attribute__((used)) static void
kgdb_trgt_dblfault_prev_register(struct frame_info *next_frame,
    void **this_cache, int regnum, int *optimizedp, enum lval_type *lvalp,
    CORE_ADDR *addrp, int *realnump, void *valuep)
{
	char dummy_valuep[MAX_REGISTER_SIZE];
	struct kgdb_tss_cache *cache;
	int ofs, regsz;

	regsz = register_size(current_gdbarch, regnum);

	if (valuep == NULL)
		valuep = dummy_valuep;
	memset(valuep, 0, regsz);
	*optimizedp = 0;
	*addrp = 0;
	*lvalp = not_lval;
	*realnump = -1;

	ofs = (regnum >= I386_EAX_REGNUM && regnum <= I386_FS_REGNUM)
	    ? kgdb_trgt_tss_offset[regnum] : -1;
	if (ofs == -1)
		return;

	cache = kgdb_trgt_tss_cache(next_frame, this_cache);
	if (cache->tss == 0)
		return;
	*addrp = cache->tss + ofs;
	*lvalp = lval_memory;
	target_read_memory(*addrp, valuep, regsz);
}