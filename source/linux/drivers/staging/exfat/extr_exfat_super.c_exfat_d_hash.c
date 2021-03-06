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
struct qstr {int /*<<< orphan*/  name; int /*<<< orphan*/  hash; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  exfat_striptail_len (struct qstr*) ; 
 int /*<<< orphan*/  full_name_hash (struct dentry const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int exfat_d_hash(const struct dentry *dentry, struct qstr *qstr)
{
	qstr->hash = full_name_hash(dentry, qstr->name,
				    exfat_striptail_len(qstr));
	return 0;
}