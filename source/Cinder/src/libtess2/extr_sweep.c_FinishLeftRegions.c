#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct TYPE_20__ {TYPE_2__* eUp; int /*<<< orphan*/  fixUpperEdge; } ;
struct TYPE_19__ {scalar_t__ Org; struct TYPE_19__* Oprev; struct TYPE_19__* Onext; int /*<<< orphan*/  Sym; int /*<<< orphan*/  Lprev; } ;
struct TYPE_18__ {int /*<<< orphan*/  env; int /*<<< orphan*/  mesh; } ;
typedef  TYPE_1__ TESStesselator ;
typedef  TYPE_2__ TESShalfEdge ;
typedef  TYPE_3__ ActiveRegion ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FinishRegion (TYPE_1__*,TYPE_3__*) ; 
 int /*<<< orphan*/  FixUpperEdge (TYPE_1__*,TYPE_3__*,TYPE_2__*) ; 
 TYPE_3__* RegionBelow (TYPE_3__*) ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 TYPE_2__* tessMeshConnect (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tessMeshSplice (int /*<<< orphan*/ ,TYPE_2__*,TYPE_2__*) ; 

__attribute__((used)) static TESShalfEdge *FinishLeftRegions( TESStesselator *tess,
									  ActiveRegion *regFirst, ActiveRegion *regLast )
/*
* We are given a vertex with one or more left-going edges.  All affected
* edges should be in the edge dictionary.  Starting at regFirst->eUp,
* we walk down deleting all regions where both edges have the same
* origin vOrg.  At the same time we copy the "inside" flag from the
* active region to the face, since at this point each face will belong
* to at most one region (this was not necessarily true until this point
* in the sweep).  The walk stops at the region above regLast; if regLast
* is NULL we walk as far as possible.  At the same time we relink the
* mesh if necessary, so that the ordering of edges around vOrg is the
* same as in the dictionary.
*/
{
	ActiveRegion *reg, *regPrev;
	TESShalfEdge *e, *ePrev;

	regPrev = regFirst;
	ePrev = regFirst->eUp;
	while( regPrev != regLast ) {
		regPrev->fixUpperEdge = FALSE;	/* placement was OK */
		reg = RegionBelow( regPrev );
		e = reg->eUp;
		if( e->Org != ePrev->Org ) {
			if( ! reg->fixUpperEdge ) {
				/* Remove the last left-going edge.  Even though there are no further
				* edges in the dictionary with this origin, there may be further
				* such edges in the mesh (if we are adding left edges to a vertex
				* that has already been processed).  Thus it is important to call
				* FinishRegion rather than just DeleteRegion.
				*/
				FinishRegion( tess, regPrev );
				break;
			}
			/* If the edge below was a temporary edge introduced by
			* ConnectRightVertex, now is the time to fix it.
			*/
			e = tessMeshConnect( tess->mesh, ePrev->Lprev, e->Sym );
			if (e == NULL) longjmp(tess->env,1);
			if ( !FixUpperEdge( tess, reg, e ) ) longjmp(tess->env,1);
		}

		/* Relink edges so that ePrev->Onext == e */
		if( ePrev->Onext != e ) {
			if ( !tessMeshSplice( tess->mesh, e->Oprev, e ) ) longjmp(tess->env,1);
			if ( !tessMeshSplice( tess->mesh, ePrev, e ) ) longjmp(tess->env,1);
		}
		FinishRegion( tess, regPrev );	/* may change reg->eUp */
		ePrev = reg->eUp;
		regPrev = reg;
	}
	return ePrev;
}