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
typedef  int /*<<< orphan*/  pthread_t ;

/* Variables and functions */
 int /*<<< orphan*/  __UNCONST (char*) ; 
 int /*<<< orphan*/  _exit (int) ; 
 int dlopen_cookie ; 
 int /*<<< orphan*/  init_fini_helper ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sleep (int) ; 
 scalar_t__ sleep_fini ; 
 int sleep_init ; 

__attribute__((used)) static void
test_dlopen(void)
{
	pthread_t t1, t2;
	sleep_init = 1;
	sleep_fini = 0;
	printf("%d\n", dlopen_cookie);
	pthread_create(&t1, NULL, init_fini_helper,
	    __UNCONST("libh_helper_dso2.so"));
	sleep(1);
	printf("%d\n", dlopen_cookie);
	if (dlopen_cookie != 1)
		_exit(1);
	sleep(1);
	pthread_create(&t2, NULL, init_fini_helper,
	    __UNCONST("libutil.so"));
	printf("%d\n", dlopen_cookie);
	if (dlopen_cookie != 1)
		_exit(1);
	_exit(0);
}