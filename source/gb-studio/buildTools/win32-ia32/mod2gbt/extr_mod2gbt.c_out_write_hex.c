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
typedef  int u8 ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  output_file ; 

void out_write_hex(u8 number)
{
    fprintf(output_file,"%02x",number);
}