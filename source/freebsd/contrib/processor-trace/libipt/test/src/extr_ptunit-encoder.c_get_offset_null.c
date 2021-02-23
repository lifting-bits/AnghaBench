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

/* Variables and functions */
 int pt_enc_get_offset (struct pt_encoder*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pte_invalid ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result get_offset_null(void)
{
	struct pt_encoder encoder;
	uint64_t offset;
	int errcode;

	errcode = pt_enc_get_offset(NULL, &offset);
	ptu_int_eq(errcode, -pte_invalid);

	errcode = pt_enc_get_offset(&encoder, NULL);
	ptu_int_eq(errcode, -pte_invalid);

	return ptu_passed();
}