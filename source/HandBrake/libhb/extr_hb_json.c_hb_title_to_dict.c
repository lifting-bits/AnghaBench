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
typedef  int /*<<< orphan*/  hb_title_t ;
typedef  int /*<<< orphan*/  hb_handle_t ;
typedef  int /*<<< orphan*/  hb_dict_t ;

/* Variables and functions */
 int /*<<< orphan*/ * hb_find_title_by_index (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * hb_title_to_dict_internal (int /*<<< orphan*/ *) ; 

hb_dict_t* hb_title_to_dict( hb_handle_t *h, int title_index )
{
    hb_title_t *title = hb_find_title_by_index(h, title_index);
    return hb_title_to_dict_internal(title);
}