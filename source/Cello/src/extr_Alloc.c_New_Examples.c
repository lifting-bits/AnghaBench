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
struct Example {char* member_0; char* member_1; } ;

/* Variables and functions */

__attribute__((used)) static struct Example* New_Examples(void) {
  
  static struct Example examples[] = {
    {
      "Usage",
      "var x = new(Int, $I(1));\n"
      "show(x); /* 1 */\n"
      "show(type_of(x)); /* Int */\n"
      "\n"
      "var y = alloc(Float);\n"
      "construct(y, $F(1.0));\n"
      "show(y); /* 1.0 */\n"
      "destruct(y);\n"
    }, {NULL, NULL}
  };
  
  return examples;
}