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
typedef  int /*<<< orphan*/  Snapshot ;
typedef  int /*<<< orphan*/  Oid ;
typedef  int /*<<< orphan*/  AclResult ;
typedef  int /*<<< orphan*/  AclMode ;

/* Variables and functions */
 int /*<<< orphan*/  ACLCHECK_NO_PRIV ; 
 int /*<<< orphan*/  ACLCHECK_OK ; 
 int /*<<< orphan*/  ACLMASK_ANY ; 
 scalar_t__ pg_largeobject_aclmask_snapshot (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

AclResult
pg_largeobject_aclcheck_snapshot(Oid lobj_oid, Oid roleid, AclMode mode,
								 Snapshot snapshot)
{
	if (pg_largeobject_aclmask_snapshot(lobj_oid, roleid, mode,
										ACLMASK_ANY, snapshot) != 0)
		return ACLCHECK_OK;
	else
		return ACLCHECK_NO_PRIV;
}