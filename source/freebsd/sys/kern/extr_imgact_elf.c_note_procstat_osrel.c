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
typedef  int /*<<< orphan*/  structsize ;
struct sbuf {int dummy; } ;
struct proc {int p_osrel; } ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int /*<<< orphan*/  sbuf_bcat (struct sbuf*,int*,int) ; 

__attribute__((used)) static void
note_procstat_osrel(void *arg, struct sbuf *sb, size_t *sizep)
{
	struct proc *p;
	size_t size;
	int structsize;

	p = (struct proc *)arg;
	size = sizeof(structsize) + sizeof(p->p_osrel);
	if (sb != NULL) {
		KASSERT(*sizep == size, ("invalid size"));
		structsize = sizeof(p->p_osrel);
		sbuf_bcat(sb, &structsize, sizeof(structsize));
		sbuf_bcat(sb, &p->p_osrel, sizeof(p->p_osrel));
	}
	*sizep = size;
}