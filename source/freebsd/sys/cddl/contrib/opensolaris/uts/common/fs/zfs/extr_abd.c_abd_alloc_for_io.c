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
typedef  int /*<<< orphan*/  boolean_t ;
typedef  int /*<<< orphan*/  abd_t ;

/* Variables and functions */
 int /*<<< orphan*/ * abd_alloc_linear (size_t,int /*<<< orphan*/ ) ; 

abd_t *
abd_alloc_for_io(size_t size, boolean_t is_metadata)
{
	return (abd_alloc_linear(size, is_metadata));
}