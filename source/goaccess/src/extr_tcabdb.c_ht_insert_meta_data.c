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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  GModule ;

/* Variables and functions */
 int /*<<< orphan*/  MTRC_METADATA ; 
 void* get_hash (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int inc_su64 (void*,char const*,int /*<<< orphan*/ ) ; 

int
ht_insert_meta_data (GModule module, const char *key, uint64_t value)
{
  void *hash = get_hash (module, MTRC_METADATA);

  if (!hash)
    return -1;

  return inc_su64 (hash, key, value);
}