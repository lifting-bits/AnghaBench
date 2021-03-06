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
typedef  int uint64 ;
typedef  enum TIFFReadDirEntryErr { ____Placeholder_TIFFReadDirEntryErr } TIFFReadDirEntryErr ;

/* Variables and functions */
 int TIFFReadDirEntryErrOk ; 
 int TIFFReadDirEntryErrRange ; 

__attribute__((used)) static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortLong8(uint64 value)
{
	if (value>0xFFFF)
		return(TIFFReadDirEntryErrRange);
	else
		return(TIFFReadDirEntryErrOk);
}