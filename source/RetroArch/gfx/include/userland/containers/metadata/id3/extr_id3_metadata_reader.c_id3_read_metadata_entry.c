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
typedef  int /*<<< orphan*/  VC_CONTAINER_T ;
struct TYPE_4__ {int size; int /*<<< orphan*/  value; } ;
typedef  TYPE_1__ VC_CONTAINER_METADATA_T ;
typedef  int /*<<< orphan*/  VC_CONTAINER_METADATA_KEY_T ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_DEBUG (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int /*<<< orphan*/  READ_BYTES (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  SKIP_BYTES (int /*<<< orphan*/ *,unsigned int) ; 
 TYPE_1__* id3_metadata_append (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static VC_CONTAINER_METADATA_T *id3_read_metadata_entry( VC_CONTAINER_T *p_ctx,
   VC_CONTAINER_METADATA_KEY_T key, unsigned int len )
{
   VC_CONTAINER_METADATA_T *meta;

   if ((meta = id3_metadata_append(p_ctx, key, len + 1)) != NULL)
   {
      unsigned int size = meta->size - 1;
      READ_BYTES(p_ctx, meta->value, size);

      if (len > size)
      {
         LOG_DEBUG(p_ctx, "metadata value truncated (%d characters lost)", len - size);
         SKIP_BYTES(p_ctx, len - size);
      }
   }
   else
   {
      SKIP_BYTES(p_ctx, len);
   }

   return meta;
}