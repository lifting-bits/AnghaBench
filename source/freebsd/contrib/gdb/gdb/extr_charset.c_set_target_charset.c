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
struct charset {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  current_host_charset ; 
 struct charset* lookup_charset_or_error (char const*) ; 
 int /*<<< orphan*/  set_host_and_target_charsets (int /*<<< orphan*/ ,struct charset*) ; 

__attribute__((used)) static void
set_target_charset (const char *charset)
{
  struct charset *cs = lookup_charset_or_error (charset);

  set_host_and_target_charsets (current_host_charset, cs);
}