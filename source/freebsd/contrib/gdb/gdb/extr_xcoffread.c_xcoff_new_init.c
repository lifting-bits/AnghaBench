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
struct objfile {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  buildsym_new_init () ; 
 int /*<<< orphan*/  stabsread_new_init () ; 

__attribute__((used)) static void
xcoff_new_init (struct objfile *objfile)
{
  stabsread_new_init ();
  buildsym_new_init ();
}