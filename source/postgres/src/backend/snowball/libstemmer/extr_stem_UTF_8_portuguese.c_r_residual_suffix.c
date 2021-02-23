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
struct SN_env {int /*<<< orphan*/  c; int /*<<< orphan*/  bra; int /*<<< orphan*/  ket; } ;

/* Variables and functions */
 int /*<<< orphan*/  a_7 ; 
 int /*<<< orphan*/  find_among_b (struct SN_env*,int /*<<< orphan*/ ,int) ; 
 int r_RV (struct SN_env*) ; 
 int slice_del (struct SN_env*) ; 

__attribute__((used)) static int r_residual_suffix(struct SN_env * z) { /* backwardmode */
    z->ket = z->c; /* [, line 184 */
    if (!(find_among_b(z, a_7, 7))) return 0; /* substring, line 184 */
    z->bra = z->c; /* ], line 184 */
    {   int ret = r_RV(z); /* call RV, line 187 */
        if (ret <= 0) return ret;
    }
    {   int ret = slice_del(z); /* delete, line 187 */
        if (ret < 0) return ret;
    }
    return 1;
}