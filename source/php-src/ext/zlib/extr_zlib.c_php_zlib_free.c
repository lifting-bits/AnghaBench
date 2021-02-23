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
typedef  scalar_t__ voidpf ;

/* Variables and functions */
 int /*<<< orphan*/  efree (void*) ; 

__attribute__((used)) static void php_zlib_free(voidpf opaque, voidpf address)
{
	efree((void*)address);
}