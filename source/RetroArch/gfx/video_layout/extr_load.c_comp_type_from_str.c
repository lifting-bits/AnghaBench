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
typedef  int /*<<< orphan*/  comp_type_t ;

/* Variables and functions */
 size_t ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  VIDEO_LAYOUT_C_UNKNOWN ; 
 int /*<<< orphan*/ * comp_type_str ; 
 scalar_t__ strcmp (char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static comp_type_t comp_type_from_str(const char *s)
{
   size_t i;

   for (i = 2; i < ARRAY_SIZE(comp_type_str); ++i)
   {
      if (strcmp(s, comp_type_str[i]) == 0)
         return (comp_type_t)(int)i;
   }

   return VIDEO_LAYOUT_C_UNKNOWN;
}