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
struct untd_hdr {int type; } ;
typedef  enum i1480u_pkt_type { ____Placeholder_i1480u_pkt_type } i1480u_pkt_type ;

/* Variables and functions */

__attribute__((used)) static inline void untd_hdr_set_type(struct untd_hdr *hdr, enum i1480u_pkt_type type)
{
	hdr->type = (hdr->type & ~0x03) | type;
}