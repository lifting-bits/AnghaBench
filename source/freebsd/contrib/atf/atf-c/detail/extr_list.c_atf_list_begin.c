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
struct list_entry {int /*<<< orphan*/  m_next; } ;
struct TYPE_4__ {struct list_entry* m_begin; } ;
typedef  TYPE_1__ atf_list_t ;
typedef  int /*<<< orphan*/  atf_list_iter_t ;

/* Variables and functions */
 int /*<<< orphan*/  entry_to_iter (TYPE_1__*,int /*<<< orphan*/ ) ; 

atf_list_iter_t
atf_list_begin(atf_list_t *l)
{
    struct list_entry *le = l->m_begin;
    return entry_to_iter(l, le->m_next);
}