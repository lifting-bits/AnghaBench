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
 int /*<<< orphan*/  CHECK_TYPEDEF (struct type*) ; 
 scalar_t__ TYPE_CODE (struct type*) ; 
 scalar_t__ TYPE_CODE_ARRAY ; 
 scalar_t__ TYPE_CODE_PTR ; 
 struct type* TYPE_TARGET_TYPE (struct type*) ; 

int
ada_is_simple_array (struct type *type)
{
  if (type == NULL)
    return 0;
  CHECK_TYPEDEF (type);
  return (TYPE_CODE (type) == TYPE_CODE_ARRAY
	  || (TYPE_CODE (type) == TYPE_CODE_PTR
	      && TYPE_CODE (TYPE_TARGET_TYPE (type)) == TYPE_CODE_ARRAY));
}