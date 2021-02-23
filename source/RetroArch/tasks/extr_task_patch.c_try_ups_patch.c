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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  scalar_t__ int64_t ;

/* Variables and functions */
 int apply_patch_content (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char*,char const*,int /*<<< orphan*/ ,void*,scalar_t__) ; 
 int /*<<< orphan*/  filestream_read_file (char const*,void**,scalar_t__*) ; 
 int /*<<< orphan*/  free (void*) ; 
 scalar_t__ path_is_valid (char const*) ; 
 int /*<<< orphan*/  string_is_empty (char const*) ; 
 int /*<<< orphan*/  ups_apply_patch ; 

__attribute__((used)) static bool try_ups_patch(bool allow_ups, const char *name_ups,
      uint8_t **buf, ssize_t *size)
{
   if (allow_ups && !string_is_empty(name_ups))
      if (path_is_valid(name_ups))
      {
         int64_t patch_size;
         bool ret                 = false;
         void *patch_data         = NULL;

         if (!filestream_read_file(name_ups, &patch_data, &patch_size))
            return false;

         if (patch_size >= 0)
         {
            ret                      = apply_patch_content(
                  buf, size, "UPS", name_ups,
                  ups_apply_patch, patch_data, patch_size);
         }

         if (patch_data)
            free(patch_data);
         return ret;
      }
   return false;
}