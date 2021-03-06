#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  magic; } ;
struct TYPE_9__ {int /*<<< orphan*/  count; TYPE_2__ info; } ;
struct TYPE_10__ {TYPE_3__ hdr; TYPE_1__* ents; } ;
typedef  TYPE_4__ xfs_dir2_leaf_t ;
typedef  int /*<<< orphan*/  xfs_dahash_t ;
struct TYPE_11__ {TYPE_4__* data; } ;
typedef  TYPE_5__ xfs_dabuf_t ;
struct TYPE_7__ {int /*<<< orphan*/  hashval; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int XFS_DIR2_LEAFN_MAGIC ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  be32_to_cpu (int /*<<< orphan*/ ) ; 

xfs_dahash_t					/* hash value */
xfs_dir2_leafn_lasthash(
	xfs_dabuf_t	*bp,			/* leaf buffer */
	int		*count)			/* count of entries in leaf */
{
	xfs_dir2_leaf_t	*leaf;			/* leaf structure */

	leaf = bp->data;
	ASSERT(be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAFN_MAGIC);
	if (count)
		*count = be16_to_cpu(leaf->hdr.count);
	if (!leaf->hdr.count)
		return 0;
	return be32_to_cpu(leaf->ents[be16_to_cpu(leaf->hdr.count) - 1].hashval);
}