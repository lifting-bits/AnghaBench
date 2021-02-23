#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  program; } ;
typedef  TYPE_1__ kvm_t ;

/* Variables and functions */
 int /*<<< orphan*/  _kvm_err (TYPE_1__*,int /*<<< orphan*/ ,char*,char const*,...) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 
 int sysctlbyname (char const*,void*,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
getsysctl(kvm_t *kd, const char *name, void *ptr, size_t len)
{
	size_t nlen = len;
	if (sysctlbyname(name, ptr, &nlen, NULL, 0) == -1) {
		_kvm_err(kd, kd->program, "cannot read sysctl %s:%s", name,
		    strerror(errno));
		return (0);
	}
	if (nlen != len) {
		_kvm_err(kd, kd->program, "sysctl %s has unexpected size", name);
		return (0);
	}
	return (1);
}