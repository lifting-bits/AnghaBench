#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64 ;
typedef  int /*<<< orphan*/  uint32 ;
typedef  scalar_t__ tmsize_t ;
struct TYPE_4__ {int /*<<< orphan*/  tif_clientdata; } ;
typedef  TYPE_1__ TIFF ;

/* Variables and functions */
 int /*<<< orphan*/  TIFFErrorExt (int /*<<< orphan*/ ,char const*,char*) ; 
 scalar_t__ TIFFRawStripSize64 (TYPE_1__*,int /*<<< orphan*/ ) ; 

tmsize_t
TIFFRawStripSize(TIFF* tif, uint32 strip)
{
	static const char module[] = "TIFFRawStripSize";
	uint64 m;
	tmsize_t n;
	m=TIFFRawStripSize64(tif,strip);
	if (m==(uint64)(-1))
		n=(tmsize_t)(-1);
	else
	{
		n=(tmsize_t)m;
		if ((uint64)n!=m)
		{
			TIFFErrorExt(tif->tif_clientdata,module,"Integer overflow");
			n=0;
		}
	}
	return(n);
}