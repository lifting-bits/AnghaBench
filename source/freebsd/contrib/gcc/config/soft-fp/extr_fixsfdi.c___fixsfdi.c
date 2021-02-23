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
typedef  int /*<<< orphan*/  UDItype ;
typedef  int /*<<< orphan*/  SFtype ;
typedef  int /*<<< orphan*/  DItype ;

/* Variables and functions */
 int /*<<< orphan*/  A ; 
 int /*<<< orphan*/  DI_BITS ; 
 int /*<<< orphan*/  FP_DECL_EX ; 
 int /*<<< orphan*/  FP_DECL_S (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_HANDLE_EXCEPTIONS ; 
 int /*<<< orphan*/  FP_TO_INT_S (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FP_UNPACK_RAW_S (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

DItype __fixsfdi(SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S(A);
  UDItype r;

  FP_UNPACK_RAW_S(A, a);
  FP_TO_INT_S(r, A, DI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}