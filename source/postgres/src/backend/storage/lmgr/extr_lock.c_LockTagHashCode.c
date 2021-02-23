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
typedef  int /*<<< orphan*/  uint32 ;
typedef  int /*<<< orphan*/  LOCKTAG ;

/* Variables and functions */
 int /*<<< orphan*/  LockMethodLockHash ; 
 int /*<<< orphan*/  get_hash_value (int /*<<< orphan*/ ,void const*) ; 

uint32
LockTagHashCode(const LOCKTAG *locktag)
{
	return get_hash_value(LockMethodLockHash, (const void *) locktag);
}