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
typedef  int /*<<< orphan*/  object_id_t ;
typedef  int /*<<< orphan*/  listree_t ;
typedef  int /*<<< orphan*/  list_t ;
typedef  int /*<<< orphan*/  list_id_t ;

/* Variables and functions */
 int /*<<< orphan*/  OTree ; 
 int SUBCATS ; 
 int /*<<< orphan*/ * __get_list_f (int /*<<< orphan*/ ,int) ; 
 int listree_get_pos_inderect (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int listree_get_pos_large (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  load_o_tree_sub (int /*<<< orphan*/ *,int) ; 
 scalar_t__ metafile_mode ; 
 scalar_t__ prepare_list_metafile (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  unpack_metafile_pointers (int /*<<< orphan*/ *) ; 

int get_entry_sublist_position (list_id_t list_id, object_id_t object_id, int mode) {
  if (metafile_mode && prepare_list_metafile (list_id, 1) < 0) {
    return -2;
  }
  list_t *L = __get_list_f (list_id, 2);
  if (!L) {
    return -1;
  }
  unpack_metafile_pointers (L);
  int cat = mode & (SUBCATS-1);
  if (!(mode & (2*SUBCATS-1))) {
    cat = -1;
  }
  listree_t LI, *LT = &LI;

  if (cat < 0) {
    return listree_get_pos_large (&OTree, object_id, 1);
  } else {
    load_o_tree_sub (LT, cat);
    return listree_get_pos_inderect (LT, object_id, 1);
  }
  //return listree_get_pos_inderect (LT, object_id, 1);
}