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
typedef  int /*<<< orphan*/  uint8_t ;
struct ptunit_result {int dummy; } ;
struct pt_insn_ext {int mode; int /*<<< orphan*/  size; int /*<<< orphan*/  raw; } ;
struct pt_insn {int mode; int /*<<< orphan*/  size; int /*<<< orphan*/  raw; } ;
typedef  int /*<<< orphan*/  insn ;
typedef  int /*<<< orphan*/  iext ;
typedef  enum pt_exec_mode { ____Placeholder_pt_exec_mode } pt_exec_mode ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct pt_insn_ext*,int /*<<< orphan*/ ,int) ; 
 int pt_ild_decode (struct pt_insn_ext*,struct pt_insn_ext*) ; 
 int /*<<< orphan*/  pte_bad_insn ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result ptunit_ild_invalid(uint8_t *raw, uint8_t size,
					       enum pt_exec_mode mode)
{
	struct pt_insn_ext iext;
	struct pt_insn insn;
	int errcode;

	memset(&iext, 0, sizeof(iext));
	memset(&insn, 0, sizeof(insn));

	memcpy(insn.raw, raw, size);
	insn.size = size;
	insn.mode = mode;

	errcode = pt_ild_decode(&insn, &iext);
	ptu_int_eq(errcode, -pte_bad_insn);

	return ptu_passed();
}