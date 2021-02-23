#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  objset_t ;
struct TYPE_8__ {int /*<<< orphan*/  dn_struct_rwlock; } ;
typedef  TYPE_1__ dnode_t ;
typedef  int /*<<< orphan*/  dmu_buf_t ;
struct TYPE_9__ {int /*<<< orphan*/  db; } ;
typedef  TYPE_2__ dmu_buf_impl_t ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  FTAG ; 
 int /*<<< orphan*/  RW_READER ; 
 int SET_ERROR (int /*<<< orphan*/ ) ; 
 TYPE_2__* dbuf_hold (TYPE_1__*,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  dbuf_whichblock (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dnode_hold (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__**) ; 
 int /*<<< orphan*/  dnode_rele (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rw_enter (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rw_exit (int /*<<< orphan*/ *) ; 

int
dmu_buf_hold_noread(objset_t *os, uint64_t object, uint64_t offset,
    void *tag, dmu_buf_t **dbp)
{
	dnode_t *dn;
	uint64_t blkid;
	dmu_buf_impl_t *db;
	int err;

	err = dnode_hold(os, object, FTAG, &dn);
	if (err)
		return (err);
	rw_enter(&dn->dn_struct_rwlock, RW_READER);
	blkid = dbuf_whichblock(dn, 0, offset);
	db = dbuf_hold(dn, blkid, tag);
	rw_exit(&dn->dn_struct_rwlock);
	dnode_rele(dn, FTAG);

	if (db == NULL) {
		*dbp = NULL;
		return (SET_ERROR(EIO));
	}

	*dbp = &db->db;
	return (err);
}