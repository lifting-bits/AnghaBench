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
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  call_void_hook (int /*<<< orphan*/ ,struct file*) ; 
 int /*<<< orphan*/  file_set_fowner ; 

void security_file_set_fowner(struct file *file)
{
	call_void_hook(file_set_fowner, file);
}