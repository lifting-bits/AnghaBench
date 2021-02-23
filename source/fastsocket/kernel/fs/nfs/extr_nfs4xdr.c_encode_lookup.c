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
struct xdr_stream {int dummy; } ;
struct qstr {int len; int /*<<< orphan*/  name; } ;
struct compound_hdr {int /*<<< orphan*/  replen; int /*<<< orphan*/  nops; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  OP_LOOKUP ; 
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 
 scalar_t__ decode_lookup_maxsz ; 
 int /*<<< orphan*/ * reserve_space (struct xdr_stream*,int) ; 
 int /*<<< orphan*/  xdr_encode_opaque (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void encode_lookup(struct xdr_stream *xdr, const struct qstr *name, struct compound_hdr *hdr)
{
	int len = name->len;
	__be32 *p;

	p = reserve_space(xdr, 8 + len);
	*p++ = cpu_to_be32(OP_LOOKUP);
	xdr_encode_opaque(p, name->name, len);
	hdr->nops++;
	hdr->replen += decode_lookup_maxsz;
}