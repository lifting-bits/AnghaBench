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
struct TYPE_5__ {struct TYPE_5__* cue_settings; struct TYPE_5__* cue_id; struct TYPE_5__* next; } ;
typedef  TYPE_1__ vtt_block_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 

vtt_block_t* vtt_block_free_head(vtt_block_t* head)
{
    vtt_block_t* next = head->next;
    if (head->cue_id != NULL) {
        free(head->cue_id);
    }
    if (head->cue_settings != NULL) {
        free(head->cue_settings);
    }
    free(head);
    return next;
}