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
 int /*<<< orphan*/  VC_FILESYS_RESET ; 
 int vc_filesys_single_param (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int vc_filesys_reset()
{
   return vc_filesys_single_param(0, VC_FILESYS_RESET);
}