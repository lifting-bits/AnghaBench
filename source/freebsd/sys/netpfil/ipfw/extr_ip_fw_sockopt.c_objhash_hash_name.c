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
typedef  int /*<<< orphan*/  uint32_t ;
struct namedobj_instance {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FNV1_32_INIT ; 
 int /*<<< orphan*/  fnv_32_str (char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint32_t
objhash_hash_name(struct namedobj_instance *ni, const void *name, uint32_t set)
{

	return (fnv_32_str((const char *)name, FNV1_32_INIT));
}