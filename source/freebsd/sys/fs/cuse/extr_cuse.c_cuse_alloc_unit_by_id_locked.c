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
struct cuse_server {int dummy; } ;

/* Variables and functions */
 int CUSE_DEVICES_MAX ; 
 int CUSE_ID_MASK ; 
 struct cuse_server** cuse_alloc_unit ; 
 int* cuse_alloc_unit_id ; 

__attribute__((used)) static int
cuse_alloc_unit_by_id_locked(struct cuse_server *pcs, int id)
{
	int n;
	int x = 0;
	int match;

	do {
		for (match = n = 0; n != CUSE_DEVICES_MAX; n++) {
			if (cuse_alloc_unit[n] != NULL) {
				if ((cuse_alloc_unit_id[n] ^ id) & CUSE_ID_MASK)
					continue;
				if ((cuse_alloc_unit_id[n] & ~CUSE_ID_MASK) == x) {
					x++;
					match = 1;
				}
			}
		}
	} while (match);

	if (x < 256) {
		for (n = 0; n != CUSE_DEVICES_MAX; n++) {
			if (cuse_alloc_unit[n] == NULL) {
				cuse_alloc_unit[n] = pcs;
				cuse_alloc_unit_id[n] = id | x;
				return (x);
			}
		}
	}
	return (-1);
}