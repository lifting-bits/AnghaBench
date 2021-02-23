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
struct SN_env {int c; int lb; int* p; } ;

/* Variables and functions */
 int /*<<< orphan*/  a_22 ; 
 int /*<<< orphan*/  find_among_b (struct SN_env*,int /*<<< orphan*/ ,int) ; 
 int r_check_vowel_harmony (struct SN_env*) ; 
 int r_mark_suffix_with_optional_y_consonant (struct SN_env*) ; 

__attribute__((used)) static int r_mark_ymUs_(struct SN_env * z) { /* backwardmode */
    {   int ret = r_check_vowel_harmony(z); /* call check_vowel_harmony, line 300 */
        if (ret <= 0) return ret;
    }
    if (z->c - 3 <= z->lb || z->p[z->c - 1] != 159) return 0; /* among, line 301 */
    if (!(find_among_b(z, a_22, 4))) return 0;
    {   int ret = r_mark_suffix_with_optional_y_consonant(z); /* call mark_suffix_with_optional_y_consonant, line 302 */
        if (ret <= 0) return ret;
    }
    return 1;
}