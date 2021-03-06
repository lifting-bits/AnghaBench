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
 int g_Bpp ; 
 char* g_bs ; 
 int g_height1 ; 
 int g_width1 ; 

int
bs_get_pixel(int x, int y)
{
  char * p;

  if (x >= 0 && x < g_width1 && y >= 0 && y < g_height1)
  {
    p = g_bs + (y * g_width1 * g_Bpp) + (x * g_Bpp);
    if (g_Bpp == 1)
    {
      return *((unsigned char *) p);
    }
    else if (g_Bpp == 2)
    {
      return *((unsigned short *) p);
    }
    else
    {
      return *((unsigned int *) p);
    }
  }
  else
  {
    return 0;
  }
}