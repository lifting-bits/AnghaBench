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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  scalar_t__ u_int ;
struct inpcbinfo {scalar_t__ ipi_hashfields; struct inpcbgroup* ipi_pcbgroups; } ;
struct inpcbgroup {int dummy; } ;

/* Variables and functions */
 scalar_t__ IPI_HASHFIELDS_2TUPLE ; 
 scalar_t__ IPI_HASHFIELDS_4TUPLE ; 
 scalar_t__ M_HASHTYPE_RSS_IPV4 ; 
 scalar_t__ M_HASHTYPE_RSS_TCP_IPV4 ; 
 scalar_t__ M_HASHTYPE_RSS_UDP_IPV4 ; 
 size_t in_pcbgroup_getbucket (struct inpcbinfo*,int /*<<< orphan*/ ) ; 

struct inpcbgroup *
in_pcbgroup_byhash(struct inpcbinfo *pcbinfo, u_int hashtype, uint32_t hash)
{

#ifdef RSS
	if ((pcbinfo->ipi_hashfields == IPI_HASHFIELDS_4TUPLE &&
	    hashtype == M_HASHTYPE_RSS_TCP_IPV4) ||
	    (pcbinfo->ipi_hashfields == IPI_HASHFIELDS_4TUPLE &&
	    hashtype == M_HASHTYPE_RSS_UDP_IPV4) ||
	    (pcbinfo->ipi_hashfields == IPI_HASHFIELDS_2TUPLE &&
	    hashtype == M_HASHTYPE_RSS_IPV4))
		return (&pcbinfo->ipi_pcbgroups[
		    in_pcbgroup_getbucket(pcbinfo, hash)]);
#endif
	return (NULL);
}