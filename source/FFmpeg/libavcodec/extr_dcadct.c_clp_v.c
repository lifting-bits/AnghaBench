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
 int clip23 (int) ; 

__attribute__((used)) static void clp_v(int *input, int len)
{
    int i;

    for (i = 0; i < len; i++)
        input[i] = clip23(input[i]);
}