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
 int /*<<< orphan*/  fopen (char*,char*) ; 
 scalar_t__ output_asm ; 
 int /*<<< orphan*/  output_file ; 

void out_open(void)
{
    output_file = fopen(output_asm ? "music.asm" : "music.c","w");
}