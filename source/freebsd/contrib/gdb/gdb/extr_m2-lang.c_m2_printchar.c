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
struct ui_file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LA_EMIT_CHAR (int,struct ui_file*,char) ; 
 int /*<<< orphan*/  fputs_filtered (char*,struct ui_file*) ; 

__attribute__((used)) static void
m2_printchar (int c, struct ui_file *stream)
{
  fputs_filtered ("'", stream);
  LA_EMIT_CHAR (c, stream, '\'');
  fputs_filtered ("'", stream);
}