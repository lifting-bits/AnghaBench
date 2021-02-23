#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/  zap_rwlock; } ;
typedef  TYPE_1__ zap_t ;
struct TYPE_12__ {TYPE_1__* zn_zap; int /*<<< orphan*/  zn_hash; } ;
typedef  TYPE_2__ zap_name_t ;
typedef  int /*<<< orphan*/  zap_leaf_t ;
typedef  int /*<<< orphan*/  zap_entry_handle_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  dmu_tx_t ;
typedef  int boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int EAGAIN ; 
 int ENOENT ; 
 int RW_LOCK_HELD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RW_WRITER ; 
 int /*<<< orphan*/  ZAP_NEED_CD ; 
 int fzap_check (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int zap_deref_leaf (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int zap_entry_create (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,void const*,int /*<<< orphan*/ *) ; 
 int zap_entry_update (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,void const*) ; 
 int zap_expand_leaf (TYPE_2__*,int /*<<< orphan*/ *,void*,int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  zap_increment_num_entries (TYPE_1__*,int,int /*<<< orphan*/ *) ; 
 int zap_leaf_lookup (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zap_put_leaf_maybe_grow_ptrtbl (TYPE_2__*,int /*<<< orphan*/ *,void*,int /*<<< orphan*/ *) ; 

int
fzap_update(zap_name_t *zn,
    int integer_size, uint64_t num_integers, const void *val,
    void *tag, dmu_tx_t *tx)
{
	zap_leaf_t *l;
	int err;
	boolean_t create;
	zap_entry_handle_t zeh;
	zap_t *zap = zn->zn_zap;

	ASSERT(RW_LOCK_HELD(&zap->zap_rwlock));
	err = fzap_check(zn, integer_size, num_integers);
	if (err != 0)
		return (err);

	err = zap_deref_leaf(zap, zn->zn_hash, tx, RW_WRITER, &l);
	if (err != 0)
		return (err);
retry:
	err = zap_leaf_lookup(l, zn, &zeh);
	create = (err == ENOENT);
	ASSERT(err == 0 || err == ENOENT);

	if (create) {
		err = zap_entry_create(l, zn, ZAP_NEED_CD,
		    integer_size, num_integers, val, &zeh);
		if (err == 0)
			zap_increment_num_entries(zap, 1, tx);
	} else {
		err = zap_entry_update(&zeh, integer_size, num_integers, val);
	}

	if (err == EAGAIN) {
		err = zap_expand_leaf(zn, l, tag, tx, &l);
		zap = zn->zn_zap;	/* zap_expand_leaf() may change zap */
		if (err == 0)
			goto retry;
	}

	if (zap != NULL)
		zap_put_leaf_maybe_grow_ptrtbl(zn, l, tag, tx);
	return (err);
}