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
typedef  char* var ;
struct Tree {int dummy; } ;
struct Header {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static var Tree_Key(struct Tree* m, var node) {
  return (char*)node + 3 * sizeof(var) + sizeof(struct Header);
}