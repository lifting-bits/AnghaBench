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
typedef  scalar_t__ U32 ;
typedef  scalar_t__ U16 ;
typedef  int /*<<< orphan*/  SCIC_REMOTE_NODE_TABLE_T ;

/* Variables and functions */
 scalar_t__ SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX ; 
 scalar_t__ SCU_SSP_REMOTE_NODE_COUNT ; 
 scalar_t__ SCU_STP_REMOTE_NODE_COUNT ; 
 scalar_t__ scic_sds_remote_node_table_allocate_single_remote_node (int /*<<< orphan*/ *,int) ; 
 scalar_t__ scic_sds_remote_node_table_allocate_triple_remote_node (int /*<<< orphan*/ *,int) ; 

U16 scic_sds_remote_node_table_allocate_remote_node(
   SCIC_REMOTE_NODE_TABLE_T * remote_node_table,
   U32                        remote_node_count
)
{
   U16 remote_node_index = SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX;

   if (remote_node_count == SCU_SSP_REMOTE_NODE_COUNT)
   {
      remote_node_index =
         scic_sds_remote_node_table_allocate_single_remote_node(
                                                         remote_node_table, 0);

      if (remote_node_index == SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX)
      {
         remote_node_index =
            scic_sds_remote_node_table_allocate_single_remote_node(
                                                         remote_node_table, 1);
      }

      if (remote_node_index == SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX)
      {
         remote_node_index =
            scic_sds_remote_node_table_allocate_single_remote_node(
                                                         remote_node_table, 2);
      }
   }
   else if (remote_node_count == SCU_STP_REMOTE_NODE_COUNT)
   {
      remote_node_index =
         scic_sds_remote_node_table_allocate_triple_remote_node(
                                                         remote_node_table, 2);
   }

   return remote_node_index;
}