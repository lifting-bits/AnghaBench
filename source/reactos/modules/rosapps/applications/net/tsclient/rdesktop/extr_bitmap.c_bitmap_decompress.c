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
typedef  int /*<<< orphan*/  uint8 ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  False ; 
 int /*<<< orphan*/  bitmap_decompress1 (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bitmap_decompress2 (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bitmap_decompress3 (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bitmap_decompressx (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int,int) ; 

BOOL
bitmap_decompress(uint8 * output, int width, int height, uint8 * input, int size, int Bpp)
{
#ifdef BITMAP_SPEED_OVER_SIZE
	BOOL rv = False;
	switch (Bpp)
	{
		case 1:
			rv = bitmap_decompress1(output, width, height, input, size);
			break;
		case 2:
			rv = bitmap_decompress2(output, width, height, input, size);
			break;
		case 3:
			rv = bitmap_decompress3(output, width, height, input, size);
			break;
	}
#else
	BOOL rv;
  rv = bitmap_decompressx(output, width, height, input, size, Bpp);
#endif
	return rv;
}