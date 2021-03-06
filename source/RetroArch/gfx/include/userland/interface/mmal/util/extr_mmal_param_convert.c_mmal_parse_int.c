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
typedef  int /*<<< orphan*/  MMAL_STATUS_T ;

/* Variables and functions */
 int /*<<< orphan*/  MMAL_EINVAL ; 
 int /*<<< orphan*/  MMAL_SUCCESS ; 
 long strtol (char const*,char**,int /*<<< orphan*/ ) ; 

MMAL_STATUS_T mmal_parse_int(int *dest, const char *str)
{
   char *endptr;
   long i = strtol(str, &endptr, 0);
   if (endptr[0] == '\0')
   {
      *dest = i;
      return MMAL_SUCCESS;
   }
   else
   {
      return MMAL_EINVAL;
   }
}