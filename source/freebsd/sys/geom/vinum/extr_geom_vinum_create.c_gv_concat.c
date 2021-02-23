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
struct gv_volume {char* name; int plexcount; char* volume; char* plex; char* drive; int plex_offset; int drive_offset; int size; scalar_t__ stripesize; int /*<<< orphan*/  org; int /*<<< orphan*/  state; } ;
struct gv_softc {char* name; int plexcount; char* volume; char* plex; char* drive; int plex_offset; int drive_offset; int size; scalar_t__ stripesize; int /*<<< orphan*/  org; int /*<<< orphan*/  state; } ;
struct gv_sd {char* name; int plexcount; char* volume; char* plex; char* drive; int plex_offset; int drive_offset; int size; scalar_t__ stripesize; int /*<<< orphan*/  org; int /*<<< orphan*/  state; } ;
struct gv_plex {char* name; int plexcount; char* volume; char* plex; char* drive; int plex_offset; int drive_offset; int size; scalar_t__ stripesize; int /*<<< orphan*/  org; int /*<<< orphan*/  state; } ;
struct gv_drive {int dummy; } ;
struct gctl_req {int dummy; } ;
struct g_geom {struct gv_volume* softc; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  GV_EVENT_CREATE_PLEX ; 
 int /*<<< orphan*/  GV_EVENT_CREATE_SD ; 
 int /*<<< orphan*/  GV_EVENT_CREATE_VOLUME ; 
 int /*<<< orphan*/  GV_EVENT_SAVE_CONFIG ; 
 int /*<<< orphan*/  GV_EVENT_SETUP_OBJECTS ; 
 int /*<<< orphan*/  GV_PLEX_CONCAT ; 
 int /*<<< orphan*/  GV_VOL_UP ; 
 int M_WAITOK ; 
 int M_ZERO ; 
 struct gv_volume* g_malloc (int,int) ; 
 int /*<<< orphan*/  gctl_error (struct gctl_req*,char*,...) ; 
 char* gctl_get_param (struct gctl_req*,char*,int /*<<< orphan*/ *) ; 
 int* gctl_get_paraml (struct gctl_req*,char*,int) ; 
 struct gv_drive* gv_find_drive (struct gv_volume*,char*) ; 
 int /*<<< orphan*/  gv_post_event (struct gv_volume*,int /*<<< orphan*/ ,struct gv_volume*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,...) ; 
 int /*<<< orphan*/  strlcpy (char*,char*,int) ; 

void
gv_concat(struct g_geom *gp, struct gctl_req *req)
{
	struct gv_drive *d;
	struct gv_sd *s;
	struct gv_volume *v;
	struct gv_plex *p;
	struct gv_softc *sc;
	char *drive, buf[30], *vol;
	int *drives, dcount;

	sc = gp->softc;
	dcount = 0;
	vol = gctl_get_param(req, "name", NULL);
	if (vol == NULL) {
		gctl_error(req, "volume name not given");	
		return;
	}

	drives = gctl_get_paraml(req, "drives", sizeof(*drives));

	if (drives == NULL) { 
		gctl_error(req, "drive names not given");
		return;
	}

	/* First we create the volume. */
	v = g_malloc(sizeof(*v), M_WAITOK | M_ZERO);
	strlcpy(v->name, vol, sizeof(v->name));
	v->state = GV_VOL_UP;
	gv_post_event(sc, GV_EVENT_CREATE_VOLUME, v, NULL, 0, 0);

	/* Then we create the plex. */
	p = g_malloc(sizeof(*p), M_WAITOK | M_ZERO);
	snprintf(p->name, sizeof(p->name), "%s.p%d", v->name, v->plexcount);
	strlcpy(p->volume, v->name, sizeof(p->volume));
	p->org = GV_PLEX_CONCAT;
	p->stripesize = 0;
	gv_post_event(sc, GV_EVENT_CREATE_PLEX, p, NULL, 0, 0);

	/* Drives are first (right now) priority */
	for (dcount = 0; dcount < *drives; dcount++) {
		snprintf(buf, sizeof(buf), "drive%d", dcount);
		drive = gctl_get_param(req, buf, NULL);
		d = gv_find_drive(sc, drive);
		if (d == NULL) {
			gctl_error(req, "No such drive '%s'", drive);
			continue;
		}
		s = g_malloc(sizeof(*s), M_WAITOK | M_ZERO);
		snprintf(s->name, sizeof(s->name), "%s.s%d", p->name, dcount);
		strlcpy(s->plex, p->name, sizeof(s->plex));
		strlcpy(s->drive, drive, sizeof(s->drive));
		s->plex_offset = -1;
		s->drive_offset = -1;
		s->size = -1;
		gv_post_event(sc, GV_EVENT_CREATE_SD, s, NULL, 0, 0);
	}
	gv_post_event(sc, GV_EVENT_SETUP_OBJECTS, sc, NULL, 0, 0);
	gv_post_event(sc, GV_EVENT_SAVE_CONFIG, sc, NULL, 0, 0);
}