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
struct TYPE_5__ {struct TYPE_5__* elems; } ;
typedef  TYPE_1__ msg_queue_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  msg_queue_clear (TYPE_1__*) ; 

void msg_queue_free(msg_queue_t *queue)
{
   if (queue)
   {
      msg_queue_clear(queue);
      free(queue->elems);
   }
   free(queue);
}