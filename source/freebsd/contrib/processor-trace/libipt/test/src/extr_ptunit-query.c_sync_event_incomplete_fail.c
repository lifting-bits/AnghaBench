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
typedef  int /*<<< orphan*/  uint64_t ;
struct ptunit_result {int dummy; } ;
struct pt_encoder {int dummy; } ;
struct pt_query_decoder {int dummy; } ;
struct ptu_decoder_fixture {struct pt_encoder encoder; struct pt_query_decoder decoder; } ;

/* Variables and functions */
 int /*<<< orphan*/  pt_encode_psb (struct pt_encoder*) ; 
 int pt_qry_sync_forward (struct pt_query_decoder*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pte_eos ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result
sync_event_incomplete_fail(struct ptu_decoder_fixture *dfix)
{
	struct pt_query_decoder *decoder = &dfix->decoder;
	struct pt_encoder *encoder = &dfix->encoder;
	uint64_t addr;
	int errcode;

	pt_encode_psb(encoder);

	errcode = pt_qry_sync_forward(decoder, &addr);
	ptu_int_eq(errcode, -pte_eos);

	return ptu_passed();
}