#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  op; scalar_t__ arg; } ;
typedef  TYPE_1__ nfs_argop4 ;
struct TYPE_5__ {int /*<<< orphan*/  createattrs; int /*<<< orphan*/  name; int /*<<< orphan*/  objtype; } ;
typedef  TYPE_2__ nfs41_create_args ;
typedef  int /*<<< orphan*/  bool_t ;
typedef  int /*<<< orphan*/  XDR ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  OP_CREATE ; 
 int /*<<< orphan*/  encode_component (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  encode_createattrs4 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  encode_createtype4 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ unexpected_op (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool_t encode_op_create(
    XDR *xdr,
    nfs_argop4 *argop)
{
    nfs41_create_args *args = (nfs41_create_args*)argop->arg;

    if (unexpected_op(argop->op, OP_CREATE))
        return FALSE;

    if (!encode_createtype4(xdr, &args->objtype))
        return FALSE;

    if (!encode_component(xdr, args->name))
        return FALSE;

    return encode_createattrs4(xdr, args->createattrs);
}