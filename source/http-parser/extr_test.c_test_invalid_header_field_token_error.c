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
 int /*<<< orphan*/  test_invalid_header_field (int,char*) ; 

void
test_invalid_header_field_token_error (int req)
{
  test_invalid_header_field(req, "Fo@: Failure");
  test_invalid_header_field(req, "Foo\01\test: Bar");
}