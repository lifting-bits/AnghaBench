#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int nest_level; scalar_t__ tuples_deleted; scalar_t__ tuples_updated; scalar_t__ tuples_inserted; } ;
struct TYPE_7__ {TYPE_3__* trans; } ;
struct TYPE_6__ {TYPE_2__* pgstat_info; } ;
typedef  TYPE_1__* Relation ;
typedef  TYPE_2__ PgStat_TableStatus ;

/* Variables and functions */
 int GetCurrentTransactionNestLevel () ; 
 int /*<<< orphan*/  add_tabstat_xact_level (TYPE_2__*,int) ; 
 int /*<<< orphan*/  pgstat_truncate_save_counters (TYPE_3__*) ; 

void
pgstat_count_truncate(Relation rel)
{
	PgStat_TableStatus *pgstat_info = rel->pgstat_info;

	if (pgstat_info != NULL)
	{
		/* We have to log the effect at the proper transactional level */
		int			nest_level = GetCurrentTransactionNestLevel();

		if (pgstat_info->trans == NULL ||
			pgstat_info->trans->nest_level != nest_level)
			add_tabstat_xact_level(pgstat_info, nest_level);

		pgstat_truncate_save_counters(pgstat_info->trans);
		pgstat_info->trans->tuples_inserted = 0;
		pgstat_info->trans->tuples_updated = 0;
		pgstat_info->trans->tuples_deleted = 0;
	}
}