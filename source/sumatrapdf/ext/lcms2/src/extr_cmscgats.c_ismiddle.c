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
typedef  int cmsBool ;

/* Variables and functions */
 int /*<<< orphan*/  isseparator (int) ; 

__attribute__((used)) static
cmsBool ismiddle(int c)
{
   return (!isseparator(c) && (c != '#') && (c !='\"') && (c != '\'') && (c > 32) && (c < 127));
}