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
 int /*<<< orphan*/  ADD_MALLOC (int /*<<< orphan*/ ) ; 
 char* strdup (char const*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

__attribute__((used)) static inline char *zzstrdup (const char *p) {
  if (!p) { return 0;}
  ADD_MALLOC (strlen (p));
  return strdup (p);
}