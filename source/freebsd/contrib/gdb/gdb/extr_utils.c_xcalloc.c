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
typedef  int /*<<< orphan*/  PTR ;

/* Variables and functions */
 int /*<<< orphan*/  xmcalloc (int /*<<< orphan*/ *,size_t,size_t) ; 

PTR				/* OK: PTR */
xcalloc (size_t number, size_t size)
{
  return xmcalloc (NULL, number, size);
}