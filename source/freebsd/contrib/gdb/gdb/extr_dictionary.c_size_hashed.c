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
struct dictionary {int dummy; } ;

/* Variables and functions */
 int DICT_HASHED_NBUCKETS (struct dictionary const*) ; 

__attribute__((used)) static int
size_hashed (const struct dictionary *dict)
{
  return DICT_HASHED_NBUCKETS (dict);
}