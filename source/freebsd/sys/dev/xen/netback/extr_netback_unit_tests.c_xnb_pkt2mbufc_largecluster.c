#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct xnb_pkt {int dummy; } ;
struct mbuf {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  ifp; } ;

/* Variables and functions */
 int MCLBYTES ; 
 size_t const M_TRAILINGSPACE (struct mbuf*) ; 
 int /*<<< orphan*/  XNB_ASSERT (int) ; 
 int /*<<< orphan*/  safe_m_freem (struct mbuf**) ; 
 int /*<<< orphan*/  xnb_get1pkt (struct xnb_pkt*,size_t const,int /*<<< orphan*/ ) ; 
 struct mbuf* xnb_pkt2mbufc (struct xnb_pkt*,int /*<<< orphan*/ ) ; 
 TYPE_1__ xnb_unit_pvt ; 

__attribute__((used)) static void
xnb_pkt2mbufc_largecluster(char *buffer, size_t buflen)
{
	const size_t size = MCLBYTES + 1;
	struct xnb_pkt pkt;
	struct mbuf *pMbuf;

	xnb_get1pkt(&pkt, size, 0);

	pMbuf = xnb_pkt2mbufc(&pkt, xnb_unit_pvt.ifp);
	XNB_ASSERT(M_TRAILINGSPACE(pMbuf) >= size);
	safe_m_freem(&pMbuf);
}