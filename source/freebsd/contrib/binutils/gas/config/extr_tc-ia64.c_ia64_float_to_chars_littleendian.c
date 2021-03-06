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
typedef  scalar_t__ LITTLENUM_TYPE ;

/* Variables and functions */
 int /*<<< orphan*/  number_to_chars_littleendian (char*,long,int) ; 

__attribute__((used)) static void
ia64_float_to_chars_littleendian (char *lit, LITTLENUM_TYPE *words,
				  int prec)
{
  while (prec--)
    {
      number_to_chars_littleendian (lit, (long) (words[prec]),
				    sizeof (LITTLENUM_TYPE));
      lit += sizeof (LITTLENUM_TYPE);
    }
}