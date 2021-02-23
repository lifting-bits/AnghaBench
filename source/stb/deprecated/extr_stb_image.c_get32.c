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
typedef  int stbi__uint32 ;
typedef  int /*<<< orphan*/  stbi ;

/* Variables and functions */
 int get16 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static stbi__uint32 get32(stbi *s)
{
   stbi__uint32 z = get16(s);
   return (z << 16) + get16(s);
}