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
struct thread {int dummy; } ;
struct freebsd32_cpuset_getaffinity_args {int /*<<< orphan*/  mask; int /*<<< orphan*/  cpusetsize; int /*<<< orphan*/  id; int /*<<< orphan*/  which; int /*<<< orphan*/  level; } ;

/* Variables and functions */
 int /*<<< orphan*/  PAIR32TO64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  id_t ; 
 int kern_cpuset_getaffinity (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
freebsd32_cpuset_getaffinity(struct thread *td,
    struct freebsd32_cpuset_getaffinity_args *uap)
{

	return (kern_cpuset_getaffinity(td, uap->level, uap->which,
	    PAIR32TO64(id_t,uap->id), uap->cpusetsize, uap->mask));
}