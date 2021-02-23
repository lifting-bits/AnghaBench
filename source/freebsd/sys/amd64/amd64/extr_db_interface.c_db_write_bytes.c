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
typedef  scalar_t__ vm_offset_t ;
typedef  void* jmp_buf ;

/* Variables and functions */
 int disable_wp () ; 
 void* kdb_jmpbuf (void*) ; 
 int /*<<< orphan*/  restore_wp (int) ; 
 int setjmp (void*) ; 

int
db_write_bytes(vm_offset_t addr, size_t size, char *data)
{
	jmp_buf jb;
	void *prev_jb;
	char *dst;
	bool old_wp;
	int ret;

	old_wp = false;
	prev_jb = kdb_jmpbuf(jb);
	ret = setjmp(jb);
	if (ret == 0) {
		old_wp = disable_wp();
		dst = (char *)addr;
		while (size-- > 0)
			*dst++ = *data++;
	}
	restore_wp(old_wp);
	(void)kdb_jmpbuf(prev_jb);
	return (ret);
}