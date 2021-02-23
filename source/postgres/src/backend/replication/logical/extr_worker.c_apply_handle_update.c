#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  TupleTableSlot ;
struct TYPE_24__ {int /*<<< orphan*/  es_tupleTable; int /*<<< orphan*/  es_result_relation_info; } ;
struct TYPE_21__ {scalar_t__ replident; } ;
struct TYPE_23__ {int /*<<< orphan*/  localrel; TYPE_1__ remoterel; } ;
struct TYPE_22__ {int /*<<< orphan*/  changed; int /*<<< orphan*/  values; } ;
typedef  int /*<<< orphan*/  StringInfo ;
typedef  int /*<<< orphan*/  Oid ;
typedef  int /*<<< orphan*/  MemoryContext ;
typedef  TYPE_2__ LogicalRepTupleData ;
typedef  TYPE_3__ LogicalRepRelMapEntry ;
typedef  int /*<<< orphan*/  LogicalRepRelId ;
typedef  TYPE_4__ EState ;
typedef  int /*<<< orphan*/  EPQState ;

/* Variables and functions */
 int /*<<< orphan*/  AfterTriggerEndQuery (TYPE_4__*) ; 
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  CommandCounterIncrement () ; 
 int /*<<< orphan*/  DEBUG1 ; 
 int /*<<< orphan*/  EvalPlanQualEnd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EvalPlanQualInit (int /*<<< orphan*/ *,TYPE_4__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  EvalPlanQualSetSlot (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ExecClearTuple (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ExecCloseIndices (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExecCopySlot (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ExecInitExtraTupleSlot (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ExecOpenIndices (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ExecResetTupleTable (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ExecSimpleRelationUpdate (TYPE_4__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FreeExecutorState (TYPE_4__*) ; 
 int /*<<< orphan*/  GetPerTupleMemoryContext (TYPE_4__*) ; 
 int /*<<< orphan*/  GetRelationIdentityOrPK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetTransactionSnapshot () ; 
 int /*<<< orphan*/  LockTupleExclusive ; 
 int /*<<< orphan*/  MemoryContextSwitchTo (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NIL ; 
 int /*<<< orphan*/  NoLock ; 
 scalar_t__ OidIsValid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PopActiveSnapshot () ; 
 int /*<<< orphan*/  PushActiveSnapshot (int /*<<< orphan*/ ) ; 
 scalar_t__ REPLICA_IDENTITY_FULL ; 
 int RelationFindReplTupleByIndex (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int RelationFindReplTupleSeq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RelationGetDescr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RelationGetRelationName (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RowExclusiveLock ; 
 int /*<<< orphan*/  TTSOpsVirtual ; 
 int /*<<< orphan*/  check_relation_updatable (TYPE_3__*) ; 
 TYPE_4__* create_estate_for_relation (TYPE_3__*) ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ensure_transaction () ; 
 int /*<<< orphan*/  logicalrep_read_update (int /*<<< orphan*/ ,int*,TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  logicalrep_rel_close (TYPE_3__*,int /*<<< orphan*/ ) ; 
 TYPE_3__* logicalrep_rel_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  should_apply_changes_for_rel (TYPE_3__*) ; 
 int /*<<< orphan*/  slot_modify_cstrings (int /*<<< orphan*/ *,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  slot_store_cstrings (int /*<<< orphan*/ *,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * table_slot_create (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
apply_handle_update(StringInfo s)
{
	LogicalRepRelMapEntry *rel;
	LogicalRepRelId relid;
	Oid			idxoid;
	EState	   *estate;
	EPQState	epqstate;
	LogicalRepTupleData oldtup;
	LogicalRepTupleData newtup;
	bool		has_oldtup;
	TupleTableSlot *localslot;
	TupleTableSlot *remoteslot;
	bool		found;
	MemoryContext oldctx;

	ensure_transaction();

	relid = logicalrep_read_update(s, &has_oldtup, &oldtup,
								   &newtup);
	rel = logicalrep_rel_open(relid, RowExclusiveLock);
	if (!should_apply_changes_for_rel(rel))
	{
		/*
		 * The relation can't become interesting in the middle of the
		 * transaction so it's safe to unlock it.
		 */
		logicalrep_rel_close(rel, RowExclusiveLock);
		return;
	}

	/* Check if we can do the update. */
	check_relation_updatable(rel);

	/* Initialize the executor state. */
	estate = create_estate_for_relation(rel);
	remoteslot = ExecInitExtraTupleSlot(estate,
										RelationGetDescr(rel->localrel),
										&TTSOpsVirtual);
	localslot = table_slot_create(rel->localrel,
								  &estate->es_tupleTable);
	EvalPlanQualInit(&epqstate, estate, NULL, NIL, -1);

	PushActiveSnapshot(GetTransactionSnapshot());
	ExecOpenIndices(estate->es_result_relation_info, false);

	/* Build the search tuple. */
	oldctx = MemoryContextSwitchTo(GetPerTupleMemoryContext(estate));
	slot_store_cstrings(remoteslot, rel,
						has_oldtup ? oldtup.values : newtup.values);
	MemoryContextSwitchTo(oldctx);

	/*
	 * Try to find tuple using either replica identity index, primary key or
	 * if needed, sequential scan.
	 */
	idxoid = GetRelationIdentityOrPK(rel->localrel);
	Assert(OidIsValid(idxoid) ||
		   (rel->remoterel.replident == REPLICA_IDENTITY_FULL && has_oldtup));

	if (OidIsValid(idxoid))
		found = RelationFindReplTupleByIndex(rel->localrel, idxoid,
											 LockTupleExclusive,
											 remoteslot, localslot);
	else
		found = RelationFindReplTupleSeq(rel->localrel, LockTupleExclusive,
										 remoteslot, localslot);

	ExecClearTuple(remoteslot);

	/*
	 * Tuple found.
	 *
	 * Note this will fail if there are other conflicting unique indexes.
	 */
	if (found)
	{
		/* Process and store remote tuple in the slot */
		oldctx = MemoryContextSwitchTo(GetPerTupleMemoryContext(estate));
		ExecCopySlot(remoteslot, localslot);
		slot_modify_cstrings(remoteslot, rel, newtup.values, newtup.changed);
		MemoryContextSwitchTo(oldctx);

		EvalPlanQualSetSlot(&epqstate, remoteslot);

		/* Do the actual update. */
		ExecSimpleRelationUpdate(estate, &epqstate, localslot, remoteslot);
	}
	else
	{
		/*
		 * The tuple to be updated could not be found.
		 *
		 * TODO what to do here, change the log level to LOG perhaps?
		 */
		elog(DEBUG1,
			 "logical replication did not find row for update "
			 "in replication target relation \"%s\"",
			 RelationGetRelationName(rel->localrel));
	}

	/* Cleanup. */
	ExecCloseIndices(estate->es_result_relation_info);
	PopActiveSnapshot();

	/* Handle queued AFTER triggers. */
	AfterTriggerEndQuery(estate);

	EvalPlanQualEnd(&epqstate);
	ExecResetTupleTable(estate->es_tupleTable, false);
	FreeExecutorState(estate);

	logicalrep_rel_close(rel, NoLock);

	CommandCounterIncrement();
}