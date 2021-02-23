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
struct pthread {int dummy; } ;

/* Variables and functions */
 void* __crt_realloc (void*,size_t) ; 
 struct pthread* _get_curthread () ; 
 int /*<<< orphan*/  thr_malloc_lock (struct pthread*) ; 
 int /*<<< orphan*/  thr_malloc_unlock (struct pthread*) ; 

void *
__thr_realloc(void *cp, size_t nbytes)
{
	struct pthread *curthread;
	void *res;

	curthread = _get_curthread();
	thr_malloc_lock(curthread);
	res = __crt_realloc(cp, nbytes);
	thr_malloc_unlock(curthread);
	return (res);
}