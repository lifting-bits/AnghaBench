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
typedef  int /*<<< orphan*/  unpack_user ;

/* Variables and functions */
 int /*<<< orphan*/  UNEXPECTED (char*) ; 

__attribute__((used)) static inline int unpack_callback_true(unpack_user* u)
{
    UNEXPECTED("true");
    return 0;
}