#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;
typedef  struct TYPE_21__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  krb5_principal ;
typedef  int /*<<< orphan*/  krb5_key_data ;
struct TYPE_22__ {TYPE_3__* db; int /*<<< orphan*/  context; } ;
typedef  TYPE_1__ kadm5_server_context ;
typedef  scalar_t__ kadm5_ret_t ;
struct TYPE_21__ {int /*<<< orphan*/  kvno; } ;
struct TYPE_23__ {TYPE_11__ entry; } ;
typedef  TYPE_2__ hdb_entry_ex ;
typedef  int /*<<< orphan*/  ent ;
struct TYPE_24__ {scalar_t__ (* hdb_open ) (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;scalar_t__ (* hdb_fetch_kvno ) (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,TYPE_2__*) ;scalar_t__ (* hdb_store ) (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,TYPE_2__*) ;int /*<<< orphan*/  (* hdb_close ) (int /*<<< orphan*/ ,TYPE_3__*) ;} ;

/* Variables and functions */
 scalar_t__ HDB_ERR_NOENTRY ; 
 int HDB_F_ADMIN_DATA ; 
 int HDB_F_GET_ANY ; 
 int /*<<< orphan*/  HDB_F_REPLACE ; 
 int KADM5_KEY_DATA ; 
 int KADM5_KVNO ; 
 int KADM5_MOD_NAME ; 
 int KADM5_MOD_TIME ; 
 int KADM5_PRINCIPAL ; 
 int KADM5_PW_EXPIRATION ; 
 int KADM5_TL_DATA ; 
 int /*<<< orphan*/  O_RDWR ; 
 scalar_t__ _kadm5_bump_pw_expire (TYPE_1__*,TYPE_11__*) ; 
 scalar_t__ _kadm5_error_code (scalar_t__) ; 
 scalar_t__ _kadm5_set_keys2 (TYPE_1__*,TYPE_11__*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ _kadm5_set_modifier (TYPE_1__*,TYPE_11__*) ; 
 int /*<<< orphan*/  hdb_free_entry (int /*<<< orphan*/ ,TYPE_2__*) ; 
 scalar_t__ hdb_seal_keys (int /*<<< orphan*/ ,TYPE_3__*,TYPE_11__*) ; 
 int /*<<< orphan*/  kadm5_log_modify (TYPE_1__*,TYPE_11__*,int) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ stub2 (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,TYPE_2__*) ; 
 scalar_t__ stub3 (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ,TYPE_3__*) ; 

kadm5_ret_t
kadm5_s_chpass_principal_with_key(void *server_handle,
				  krb5_principal princ,
				  int n_key_data,
				  krb5_key_data *key_data)
{
    kadm5_server_context *context = server_handle;
    hdb_entry_ex ent;
    kadm5_ret_t ret;

    memset(&ent, 0, sizeof(ent));
    ret = context->db->hdb_open(context->context, context->db, O_RDWR, 0);
    if(ret)
	return ret;
    ret = context->db->hdb_fetch_kvno(context->context, context->db, princ, 0,
				      HDB_F_GET_ANY|HDB_F_ADMIN_DATA, &ent);
    if(ret == HDB_ERR_NOENTRY)
	goto out;
    ret = _kadm5_set_keys2(context, &ent.entry, n_key_data, key_data);
    if(ret)
	goto out2;
    ent.entry.kvno++;
    ret = _kadm5_set_modifier(context, &ent.entry);
    if(ret)
	goto out2;
    ret = _kadm5_bump_pw_expire(context, &ent.entry);
    if (ret)
	goto out2;

    ret = hdb_seal_keys(context->context, context->db, &ent.entry);
    if (ret)
	goto out2;

    ret = context->db->hdb_store(context->context, context->db,
				 HDB_F_REPLACE, &ent);
    if (ret)
	goto out2;

    kadm5_log_modify (context,
		      &ent.entry,
		      KADM5_PRINCIPAL | KADM5_MOD_NAME | KADM5_MOD_TIME |
		      KADM5_KEY_DATA | KADM5_KVNO | KADM5_PW_EXPIRATION |
		      KADM5_TL_DATA);

out2:
    hdb_free_entry(context->context, &ent);
out:
    context->db->hdb_close(context->context, context->db);
    return _kadm5_error_code(ret);
}