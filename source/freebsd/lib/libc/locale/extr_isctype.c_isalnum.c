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
 int _CTYPE_A ; 
 int _CTYPE_N ; 
 int __sbistype (int,int) ; 

int
isalnum(int c)
{
	return (__sbistype(c, _CTYPE_A|_CTYPE_N));
}