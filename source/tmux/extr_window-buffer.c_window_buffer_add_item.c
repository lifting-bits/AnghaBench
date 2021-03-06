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
struct window_buffer_modedata {scalar_t__ item_size; struct window_buffer_itemdata** item_list; } ;
struct window_buffer_itemdata {int dummy; } ;

/* Variables and functions */
 struct window_buffer_itemdata* xcalloc (int,int) ; 
 struct window_buffer_itemdata** xreallocarray (struct window_buffer_itemdata**,scalar_t__,int) ; 

__attribute__((used)) static struct window_buffer_itemdata *
window_buffer_add_item(struct window_buffer_modedata *data)
{
	struct window_buffer_itemdata	*item;

	data->item_list = xreallocarray(data->item_list, data->item_size + 1,
	    sizeof *data->item_list);
	item = data->item_list[data->item_size++] = xcalloc(1, sizeof *item);
	return (item);
}