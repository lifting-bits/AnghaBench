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
typedef  int /*<<< orphan*/  tree ;

/* Variables and functions */
 int DECL_UID (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
sort_tags_by_id (const void *pa, const void *pb)
{
  tree a = *(tree *)pa;
  tree b = *(tree *)pb;
 
  return DECL_UID (a) - DECL_UID (b);
}