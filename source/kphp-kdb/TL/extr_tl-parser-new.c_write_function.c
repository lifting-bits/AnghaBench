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
struct tl_constructor {int dummy; } ;

/* Variables and functions */
 int TLS_COMBINATOR ; 
 int schema_version ; 
 int /*<<< orphan*/  wint (int) ; 
 int /*<<< orphan*/  write_combinator (struct tl_constructor*) ; 

void write_function (struct tl_constructor *c) {
  wint (schema_version >= 1 ? TLS_COMBINATOR : 3);
  write_combinator (c);
}