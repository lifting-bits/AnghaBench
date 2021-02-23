#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct ptunit_result {int dummy; } ;
struct image_fixture {int /*<<< orphan*/ * asid; int /*<<< orphan*/  image; TYPE_2__* status; TYPE_1__* section; } ;
struct TYPE_4__ {int deleted; } ;
struct TYPE_3__ {int /*<<< orphan*/  filename; } ;

/* Variables and functions */
 int pt_image_read (int /*<<< orphan*/ *,int*,int*,int,int /*<<< orphan*/ *,int) ; 
 int pt_image_remove_by_filename (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptu_int_eq (int,int) ; 
 struct ptunit_result ptu_passed () ; 
 int /*<<< orphan*/  ptu_uint_eq (int,int) ; 

__attribute__((used)) static struct ptunit_result
remove_by_filename_bad_asid(struct image_fixture *ifix)
{
	uint8_t buffer[] = { 0xcc, 0xcc, 0xcc };
	int status, isid;

	isid = -1;
	status = pt_image_read(&ifix->image, &isid, buffer, 2, &ifix->asid[0],
			       0x1001ull);
	ptu_int_eq(status, 2);
	ptu_int_eq(isid, 10);
	ptu_uint_eq(buffer[0], 0x01);
	ptu_uint_eq(buffer[1], 0x02);
	ptu_uint_eq(buffer[2], 0xcc);

	status = pt_image_remove_by_filename(&ifix->image,
					     ifix->section[0].filename,
					     &ifix->asid[1]);
	ptu_int_eq(status, 0);

	ptu_int_eq(ifix->status[0].deleted, 0);
	ptu_int_eq(ifix->status[1].deleted, 0);

	isid = -1;
	status = pt_image_read(&ifix->image, &isid, buffer, 2, &ifix->asid[0],
			       0x1003ull);
	ptu_int_eq(status, 2);
	ptu_int_eq(isid, 10);
	ptu_uint_eq(buffer[0], 0x03);
	ptu_uint_eq(buffer[1], 0x04);
	ptu_uint_eq(buffer[2], 0xcc);

	isid = -1;
	status = pt_image_read(&ifix->image, &isid, buffer, 2, &ifix->asid[1],
			       0x2005ull);
	ptu_int_eq(status, 2);
	ptu_int_eq(isid, 11);
	ptu_uint_eq(buffer[0], 0x05);
	ptu_uint_eq(buffer[1], 0x06);
	ptu_uint_eq(buffer[2], 0xcc);

	return ptu_passed();
}