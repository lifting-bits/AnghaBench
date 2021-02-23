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

/* Variables and functions */
 int /*<<< orphan*/  LOG_DEBUG (char*) ; 
 int /*<<< orphan*/  free (void*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 void* tcadbget (void*,char const*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  tcadbput (void*,char const*,int /*<<< orphan*/ ,int*,int) ; 

__attribute__((used)) static int
inc_si32 (void *hash, const char *key, int inc)
{
  int value = inc, sp;
  void *ptr;

  if (!hash)
    return -1;

  if ((ptr = tcadbget (hash, key, strlen (key), &sp)) != NULL) {
    value = (*(int *) ptr) + inc;
    free (ptr);
  }

  /* if key exists in the database, it is overwritten */
  if (!tcadbput (hash, key, strlen (key), &value, sizeof (int)))
    LOG_DEBUG (("Unable to tcadbput\n"));

  return 0;
}