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
typedef  int /*<<< orphan*/  SFtype ;

/* Variables and functions */
 int /*<<< orphan*/  A ; 
 int /*<<< orphan*/  B ; 
 int /*<<< orphan*/  FP_CMP_EQ_S (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_DECL_EX ; 
 int /*<<< orphan*/  FP_DECL_S (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_EX_INVALID ; 
 int /*<<< orphan*/  FP_HANDLE_EXCEPTIONS ; 
 scalar_t__ FP_ISSIGNAN_S (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_SET_EXCEPTION (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_UNPACK_RAW_S (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int __eqsf2(SFtype a, SFtype b)
{
  FP_DECL_EX;
  FP_DECL_S(A); FP_DECL_S(B);
  int r;

  FP_UNPACK_RAW_S(A, a);
  FP_UNPACK_RAW_S(B, b);
  FP_CMP_EQ_S(r, A, B);
  if (r && (FP_ISSIGNAN_S(A) || FP_ISSIGNAN_S(B)))
    FP_SET_EXCEPTION(FP_EX_INVALID);
  FP_HANDLE_EXCEPTIONS;

  return r;
}