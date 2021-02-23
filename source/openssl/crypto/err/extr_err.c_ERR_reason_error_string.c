#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {char const* string; void* error; } ;
typedef  TYPE_1__ ERR_STRING_DATA ;

/* Variables and functions */
 unsigned long ERR_GET_LIB (unsigned long) ; 
 unsigned long ERR_GET_REASON (unsigned long) ; 
 void* ERR_PACK (unsigned long,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  RUN_ONCE (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_err_strings_init ; 
 int /*<<< orphan*/  err_string_init ; 
 TYPE_1__* int_err_get_item (TYPE_1__*) ; 

const char *ERR_reason_error_string(unsigned long e)
{
    ERR_STRING_DATA d, *p = NULL;
    unsigned long l, r;

    if (!RUN_ONCE(&err_string_init, do_err_strings_init)) {
        return NULL;
    }

    l = ERR_GET_LIB(e);
    r = ERR_GET_REASON(e);
    d.error = ERR_PACK(l, 0, r);
    p = int_err_get_item(&d);
    if (p == NULL) {
        d.error = ERR_PACK(0, 0, r);
        p = int_err_get_item(&d);
    }
    return ((p == NULL) ? NULL : p->string);
}