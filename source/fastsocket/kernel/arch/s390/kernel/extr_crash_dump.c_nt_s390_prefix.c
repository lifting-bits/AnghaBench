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
struct save_area_s390x {int /*<<< orphan*/  pref_reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  KEXEC_CORE_NOTE_NAME ; 
 int /*<<< orphan*/  NT_S390_PREFIX ; 
 void* nt_init (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *nt_s390_prefix(void *ptr, struct save_area_s390x *sa)
{
	return nt_init(ptr, NT_S390_PREFIX, &sa->pref_reg,
			 sizeof(sa->pref_reg), KEXEC_CORE_NOTE_NAME);
}