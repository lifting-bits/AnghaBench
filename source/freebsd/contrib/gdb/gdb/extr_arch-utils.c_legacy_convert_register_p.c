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
struct type {int dummy; } ;

/* Variables and functions */
 scalar_t__ DEPRECATED_REGISTER_CONVERTIBLE (int) ; 
 scalar_t__ DEPRECATED_REGISTER_CONVERTIBLE_P () ; 

int
legacy_convert_register_p (int regnum, struct type *type)
{
  return (DEPRECATED_REGISTER_CONVERTIBLE_P ()
	  && DEPRECATED_REGISTER_CONVERTIBLE (regnum));
}