#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  node; scalar_t__ off; } ;
typedef  TYPE_1__ rangepoint_t ;
typedef  scalar_t__ nsresult ;
typedef  int /*<<< orphan*/  nsIDOMNode ;
typedef  int /*<<< orphan*/  UINT32 ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ NS_OK ; 
 scalar_t__ TEXT_NODE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free_rangepoint (TYPE_1__*) ; 
 int /*<<< orphan*/  get_child_count (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_child_index (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * get_child_node (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ get_node_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_text_length (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_rangepoint (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ nsIDOMNode_GetParentNode (int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  nsIDOMNode_Release (int /*<<< orphan*/ *) ; 

__attribute__((used)) static BOOL rangepoint_prev_node(rangepoint_t *iter)
{
    nsIDOMNode *node;
    UINT32 off;
    nsresult nsres;

    /* Try to move to the child node. */
    if(iter->off) {
        node = get_child_node(iter->node, iter->off-1);
        assert(node != NULL);

        off = get_node_type(node) == TEXT_NODE ? get_text_length(node) : get_child_count(node);
        free_rangepoint(iter);
        init_rangepoint(iter, node, off);
        nsIDOMNode_Release(node);
        return TRUE;
    }

    /* There are no more children in the node. Move to parent. */
    nsres = nsIDOMNode_GetParentNode(iter->node, &node);
    assert(nsres == NS_OK);
    if(!node)
        return FALSE;

    off = get_child_index(node, iter->node);
    free_rangepoint(iter);
    init_rangepoint(iter, node, off);
    return TRUE;
}