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
struct scc_mode {struct scc_chan* m_chan; } ;
struct scc_chan {int /*<<< orphan*/  ch_rlist; } ;
struct resource_list_entry {int dummy; } ;
struct resource {int dummy; } ;
typedef  scalar_t__ device_t ;

/* Variables and functions */
 int EINVAL ; 
 struct scc_mode* device_get_ivars (scalar_t__) ; 
 scalar_t__ device_get_parent (scalar_t__) ; 
 struct resource_list_entry* resource_list_find (int /*<<< orphan*/ *,int,int) ; 

int
scc_bus_release_resource(device_t dev, device_t child, int type, int rid,
    struct resource *res)
{
	struct resource_list_entry *rle;
	struct scc_chan *ch;
	struct scc_mode *m;

	if (device_get_parent(child) != dev)
		return (EINVAL);

	m = device_get_ivars(child);
	ch = m->m_chan;
	rle = resource_list_find(&ch->ch_rlist, type, rid);
	return ((rle == NULL) ? EINVAL : 0);
}