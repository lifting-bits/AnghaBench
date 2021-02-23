#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_5__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  mpfr_t ;
struct TYPE_6__ {int /*<<< orphan*/  mf; } ;
typedef  TYPE_1__ calc_number_t ;
struct TYPE_7__ {void* is_nan; } ;

/* Variables and functions */
 int /*<<< orphan*/  MPFR_DEFAULT_RND ; 
 void* TRUE ; 
 int /*<<< orphan*/  build_rad_const (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_5__ calc ; 
 int /*<<< orphan*/  mpfr_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_cmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_number_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_tan (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rpn_zero (TYPE_1__*) ; 
 int /*<<< orphan*/  validate_angle2rad (TYPE_1__*) ; 

void rpn_tan(calc_number_t *c)
{
    mpfr_t mp_pi, mp_pi_2, mp_3_pi_2, mp_2_pi;

    validate_angle2rad(c);
    build_rad_const(&mp_pi, &mp_pi_2, &mp_3_pi_2, &mp_2_pi);

    if (!mpfr_cmp(c->mf, mp_pi_2) || !mpfr_cmp(c->mf, mp_3_pi_2))
        calc.is_nan = TRUE;
    else
    if (!mpfr_cmp(c->mf, mp_pi) || !mpfr_cmp(c->mf, mp_2_pi))
        rpn_zero(c);
    else {
        mpfr_tan(c->mf, c->mf, MPFR_DEFAULT_RND);
        if (!mpfr_number_p(c->mf)) calc.is_nan = TRUE;
    }
    mpfr_clear(mp_pi);
    mpfr_clear(mp_pi_2);
    mpfr_clear(mp_3_pi_2);
    mpfr_clear(mp_2_pi);
}