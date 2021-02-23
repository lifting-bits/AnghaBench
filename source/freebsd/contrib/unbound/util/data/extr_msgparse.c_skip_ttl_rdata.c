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
typedef  int uint16_t ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  sldns_buffer ;

/* Variables and functions */
 int sldns_buffer_read_u16 (int /*<<< orphan*/ *) ; 
 int sldns_buffer_remaining (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sldns_buffer_skip (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
skip_ttl_rdata(sldns_buffer* pkt) 
{
	uint16_t rdatalen;
	if(sldns_buffer_remaining(pkt) < 6) /* ttl + rdatalen */
		return 0;
	sldns_buffer_skip(pkt, 4); /* ttl */
	rdatalen = sldns_buffer_read_u16(pkt);
	if(sldns_buffer_remaining(pkt) < rdatalen)
		return 0;
	sldns_buffer_skip(pkt, (ssize_t)rdatalen);
	return 1;
}