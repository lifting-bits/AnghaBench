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
typedef  int /*<<< orphan*/  Sym ;

/* Variables and functions */
 int /*<<< orphan*/  resolve_sym (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * sym_get (char const*) ; 

Sym *resolve_name(const char *name) {
    Sym *sym = sym_get(name);
    if (!sym) {
        return NULL;
    }
    resolve_sym(sym);
    return sym;
}