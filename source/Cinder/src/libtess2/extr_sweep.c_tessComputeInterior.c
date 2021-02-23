#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct TYPE_21__ {TYPE_1__* eUp; } ;
struct TYPE_20__ {int /*<<< orphan*/  mesh; int /*<<< orphan*/  dict; int /*<<< orphan*/  event; int /*<<< orphan*/  pq; } ;
struct TYPE_19__ {int /*<<< orphan*/  anEdge; } ;
struct TYPE_18__ {int /*<<< orphan*/  Org; } ;
typedef  TYPE_2__ TESSvertex ;
typedef  TYPE_3__ TESStesselator ;
typedef  TYPE_4__ ActiveRegion ;

/* Variables and functions */
 int /*<<< orphan*/  DebugEvent (TYPE_3__*) ; 
 int /*<<< orphan*/  DoneEdgeDict (TYPE_3__*) ; 
 int /*<<< orphan*/  DonePriorityQ (TYPE_3__*) ; 
 int /*<<< orphan*/  InitEdgeDict (TYPE_3__*) ; 
 int /*<<< orphan*/  InitPriorityQ (TYPE_3__*) ; 
 int /*<<< orphan*/  RemoveDegenerateEdges (TYPE_3__*) ; 
 int /*<<< orphan*/  RemoveDegenerateFaces (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SpliceMergeVertices (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SweepEvent (TYPE_3__*,TYPE_2__*) ; 
 int /*<<< orphan*/  VertEq (TYPE_2__*,TYPE_2__*) ; 
 scalar_t__ dictKey (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dictMin (int /*<<< orphan*/ ) ; 
 scalar_t__ pqExtractMin (int /*<<< orphan*/ ) ; 
 scalar_t__ pqMinimum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tessMeshCheckMesh (int /*<<< orphan*/ ) ; 

int tessComputeInterior( TESStesselator *tess )
/*
* tessComputeInterior( tess ) computes the planar arrangement specified
* by the given contours, and further subdivides this arrangement
* into regions.  Each region is marked "inside" if it belongs
* to the polygon, according to the rule given by tess->windingRule.
* Each interior region is guaranteed be monotone.
*/
{
	TESSvertex *v, *vNext;

	/* Each vertex defines an event for our sweep line.  Start by inserting
	* all the vertices in a priority queue.  Events are processed in
	* lexicographic order, ie.
	*
	*	e1 < e2  iff  e1.x < e2.x || (e1.x == e2.x && e1.y < e2.y)
	*/
	RemoveDegenerateEdges( tess );
	if ( !InitPriorityQ( tess ) ) return 0; /* if error */
	InitEdgeDict( tess );

	while( (v = (TESSvertex *)pqExtractMin( tess->pq )) != NULL ) {
		for( ;; ) {
			vNext = (TESSvertex *)pqMinimum( tess->pq );
			if( vNext == NULL || ! VertEq( vNext, v )) break;

			/* Merge together all vertices at exactly the same location.
			* This is more efficient than processing them one at a time,
			* simplifies the code (see ConnectLeftDegenerate), and is also
			* important for correct handling of certain degenerate cases.
			* For example, suppose there are two identical edges A and B
			* that belong to different contours (so without this code they would
			* be processed by separate sweep events).  Suppose another edge C
			* crosses A and B from above.  When A is processed, we split it
			* at its intersection point with C.  However this also splits C,
			* so when we insert B we may compute a slightly different
			* intersection point.  This might leave two edges with a small
			* gap between them.  This kind of error is especially obvious
			* when using boundary extraction (TESS_BOUNDARY_ONLY).
			*/
			vNext = (TESSvertex *)pqExtractMin( tess->pq );
			SpliceMergeVertices( tess, v->anEdge, vNext->anEdge );
		}
		SweepEvent( tess, v );
	}

	/* Set tess->event for debugging purposes */
	tess->event = ((ActiveRegion *) dictKey( dictMin( tess->dict )))->eUp->Org;
	DebugEvent( tess );
	DoneEdgeDict( tess );
	DonePriorityQ( tess );

	if ( !RemoveDegenerateFaces( tess, tess->mesh ) ) return 0;
	tessMeshCheckMesh( tess->mesh );

	return 1;
}