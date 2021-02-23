#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  krb5_error_code ;
typedef  int /*<<< orphan*/  krb5_context ;
typedef  int /*<<< orphan*/  hdb_entry ;
struct TYPE_3__ {scalar_t__ hdb_master_key_set; int /*<<< orphan*/  hdb_master_key; } ;
typedef  TYPE_1__ HDB ;

/* Variables and functions */
 int /*<<< orphan*/  hdb_seal_keys_mkey (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

krb5_error_code
hdb_seal_keys(krb5_context context, HDB *db, hdb_entry *ent)
{
    if (db->hdb_master_key_set == 0)
	return 0;

    return hdb_seal_keys_mkey(context, ent, db->hdb_master_key);
}