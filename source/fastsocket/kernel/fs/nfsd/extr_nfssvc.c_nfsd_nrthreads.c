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
struct TYPE_2__ {int sv_nrthreads; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nfsd_mutex ; 
 TYPE_1__* nfsd_serv ; 

int nfsd_nrthreads(void)
{
	int rv = 0;
	mutex_lock(&nfsd_mutex);
	if (nfsd_serv)
		rv = nfsd_serv->sv_nrthreads;
	mutex_unlock(&nfsd_mutex);
	return rv;
}