#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int need_push; int /*<<< orphan*/ * list; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; void* label; int /*<<< orphan*/  path; int /*<<< orphan*/  enum_idx; int /*<<< orphan*/  type_default; void* exts; } ;
typedef  TYPE_1__ menu_displaylist_info_t ;
typedef  int /*<<< orphan*/  file_list_t ;

/* Variables and functions */
 int /*<<< orphan*/  DISPLAYLIST_MAIN_MENU ; 
 int /*<<< orphan*/  FILE_TYPE_PLAIN ; 
 int /*<<< orphan*/  MENU_ENUM_LABEL_MAIN_MENU ; 
 int /*<<< orphan*/  menu_displaylist_ctl (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  menu_displaylist_info_free (TYPE_1__*) ; 
 int /*<<< orphan*/  menu_displaylist_info_init (TYPE_1__*) ; 
 int /*<<< orphan*/  menu_displaylist_process (TYPE_1__*) ; 
 int /*<<< orphan*/  menu_entries_append_enum (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * menu_entries_get_menu_stack_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * menu_entries_get_selection_buf_ptr (int /*<<< orphan*/ ) ; 
 char* msg_hash_to_str (int /*<<< orphan*/ ) ; 
 void* strdup (char*) ; 

__attribute__((used)) static bool stripes_menu_init_list(void *data)
{
   menu_displaylist_info_t info;

   file_list_t *menu_stack      = menu_entries_get_menu_stack_ptr(0);
   file_list_t *selection_buf   = menu_entries_get_selection_buf_ptr(0);

   menu_displaylist_info_init(&info);

   info.label                   = strdup(
         msg_hash_to_str(MENU_ENUM_LABEL_MAIN_MENU));
   info.exts                    = strdup("lpl");
   info.type_default            = FILE_TYPE_PLAIN;
   info.enum_idx                = MENU_ENUM_LABEL_MAIN_MENU;

   menu_entries_append_enum(menu_stack, info.path,
         info.label,
         MENU_ENUM_LABEL_MAIN_MENU,
         info.type, info.flags, 0);

   info.list  = selection_buf;

   if (!menu_displaylist_ctl(DISPLAYLIST_MAIN_MENU, &info))
      goto error;

   info.need_push = true;

   if (!menu_displaylist_process(&info))
      goto error;

   menu_displaylist_info_free(&info);
   return true;

error:
   menu_displaylist_info_free(&info);
   return false;
}