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
struct df_ref {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  df_ref_debug (struct df_ref*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 

void
debug_df_ref (struct df_ref *ref)
{
  df_ref_debug (ref, stderr);
}