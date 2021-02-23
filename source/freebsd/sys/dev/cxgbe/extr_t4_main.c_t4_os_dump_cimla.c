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
struct sbuf {int dummy; } ;
struct adapter {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_DEBUG ; 
 int /*<<< orphan*/  M_NOWAIT ; 
 int /*<<< orphan*/  SBUF_AUTOEXTEND ; 
 int /*<<< orphan*/  device_get_nameunit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  log (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sbuf_cim_la (struct adapter*,struct sbuf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sbuf_data (struct sbuf*) ; 
 int /*<<< orphan*/  sbuf_delete (struct sbuf*) ; 
 int sbuf_finish (struct sbuf*) ; 
 struct sbuf* sbuf_new (struct sbuf*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

bool
t4_os_dump_cimla(struct adapter *sc, int arg, bool verbose)
{
	struct sbuf sb;
	int rc;

	if (sbuf_new(&sb, NULL, 4096, SBUF_AUTOEXTEND) != &sb)
		return (false);
	rc = sbuf_cim_la(sc, &sb, M_NOWAIT);
	if (rc == 0) {
		rc = sbuf_finish(&sb);
		if (rc == 0) {
			log(LOG_DEBUG, "%s: CIM LA dump follows.\n%s",
		    		device_get_nameunit(sc->dev), sbuf_data(&sb));
		}
	}
	sbuf_delete(&sb);
	return (false);
}