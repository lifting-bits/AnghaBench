#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint32 ;
struct TYPE_11__ {int /*<<< orphan*/  style; } ;
struct TYPE_10__ {void* y; void* x; } ;
struct TYPE_9__ {int opcode; int fillmode; int npoints; int datasize; int* data; int /*<<< orphan*/  fgcolour; int /*<<< orphan*/  bgcolour; TYPE_4__ brush; void* y; void* x; } ;
typedef  int /*<<< orphan*/  STREAM ;
typedef  int /*<<< orphan*/  RDPCLIENT ;
typedef  TYPE_1__ POLYGON2_ORDER ;
typedef  TYPE_2__ POINT ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG (char*) ; 
 int /*<<< orphan*/  error (char*,...) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  in_uint8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint8a (int /*<<< orphan*/ ,int*,int) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 void* parse_delta (int*,int*) ; 
 int /*<<< orphan*/  rdp_in_colour (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rdp_in_coord (int /*<<< orphan*/ ,void**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rdp_parse_brush (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 int /*<<< orphan*/  ui_polygon (int /*<<< orphan*/ *,int,int,TYPE_2__*,int,TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
process_polygon2(RDPCLIENT * This, STREAM s, POLYGON2_ORDER * os, uint32 present, BOOL delta)
{
	int index, data, next;
	uint8 flags = 0;
	POINT *points;

	if (present & 0x0001)
		rdp_in_coord(s, &os->x, delta);

	if (present & 0x0002)
		rdp_in_coord(s, &os->y, delta);

	if (present & 0x0004)
		in_uint8(s, os->opcode);

	if (present & 0x0008)
		in_uint8(s, os->fillmode);

	if (present & 0x0010)
		rdp_in_colour(s, &os->bgcolour);

	if (present & 0x0020)
		rdp_in_colour(s, &os->fgcolour);

	rdp_parse_brush(s, &os->brush, present >> 6);

	if (present & 0x0800)
		in_uint8(s, os->npoints);

	if (present & 0x1000)
	{
		in_uint8(s, os->datasize);
		in_uint8a(s, os->data, os->datasize);
	}

	DEBUG(("POLYGON2(x=%d,y=%d,op=0x%x,fm=%d,bs=%d,bg=0x%x,fg=0x%x,n=%d,sz=%d)\n",
	       os->x, os->y, os->opcode, os->fillmode, os->brush.style, os->bgcolour, os->fgcolour,
	       os->npoints, os->datasize));

	DEBUG(("Data: "));

	for (index = 0; index < os->datasize; index++)
		DEBUG(("%02x ", os->data[index]));

	DEBUG(("\n"));

	if (os->opcode < 0x01 || os->opcode > 0x10)
	{
		error("bad ROP2 0x%x\n", os->opcode);
		return;
	}

	points = (POINT *) malloc((os->npoints + 1) * sizeof(POINT));

	if(points == NULL)
		return;

	memset(points, 0, (os->npoints + 1) * sizeof(POINT));

	points[0].x = os->x;
	points[0].y = os->y;

	index = 0;
	data = ((os->npoints - 1) / 4) + 1;
	for (next = 1; (next <= os->npoints) && (next < 256) && (data < os->datasize); next++)
	{
		if ((next - 1) % 4 == 0)
			flags = os->data[index++];

		if (~flags & 0x80)
			points[next].x = parse_delta(os->data, &data);

		if (~flags & 0x40)
			points[next].y = parse_delta(os->data, &data);

		flags <<= 2;
	}

	if (next - 1 == os->npoints)
#if 0
		ui_polygon(This, os->opcode - 1, os->fillmode, points, os->npoints + 1,
			   &os->brush, os->bgcolour, os->fgcolour);
#else
		ui_polygon(This, os->opcode, os->fillmode, points, os->npoints + 1,
			   &os->brush, os->bgcolour, os->fgcolour);
#endif
	else
		error("polygon2 parse error\n");

	free(points);
}