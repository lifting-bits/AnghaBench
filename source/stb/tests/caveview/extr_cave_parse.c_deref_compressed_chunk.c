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
struct TYPE_4__ {scalar_t__ refcount; struct TYPE_4__* data; } ;
typedef  TYPE_1__ compressed_chunk ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 

__attribute__((used)) static void deref_compressed_chunk(compressed_chunk *cc)
{
   assert(cc->refcount > 0);
   --cc->refcount;
   if (cc->refcount == 0) {
      if (cc->data)
         free(cc->data);
      free(cc);
   }
}