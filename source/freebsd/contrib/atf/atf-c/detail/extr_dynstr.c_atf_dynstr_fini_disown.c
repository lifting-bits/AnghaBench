#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {char* m_data; } ;
typedef  TYPE_1__ atf_dynstr_t ;

/* Variables and functions */
 int /*<<< orphan*/  INV (int /*<<< orphan*/ ) ; 

char *
atf_dynstr_fini_disown(atf_dynstr_t *ad)
{
    INV(ad->m_data != NULL);
    return ad->m_data;
}