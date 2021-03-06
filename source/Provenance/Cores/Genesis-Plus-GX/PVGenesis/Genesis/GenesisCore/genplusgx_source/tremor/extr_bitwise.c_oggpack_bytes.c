#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {long count; long headptr; int headbit; TYPE_2__* head; } ;
typedef  TYPE_3__ oggpack_buffer ;
struct TYPE_6__ {long begin; TYPE_1__* buffer; } ;
struct TYPE_5__ {long data; } ;

/* Variables and functions */

long oggpack_bytes(oggpack_buffer *b){
  return(b->count+b->headptr-b->head->buffer->data-b->head->begin+
         (b->headbit+7)/8);
}