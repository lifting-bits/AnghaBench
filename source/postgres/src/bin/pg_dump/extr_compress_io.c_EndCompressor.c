#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ comprAlg; } ;
typedef  TYPE_1__ CompressorState ;
typedef  int /*<<< orphan*/  ArchiveHandle ;

/* Variables and functions */
 scalar_t__ COMPR_ALG_LIBZ ; 
 int /*<<< orphan*/  EndCompressorZlib (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 

void
EndCompressor(ArchiveHandle *AH, CompressorState *cs)
{
#ifdef HAVE_LIBZ
	if (cs->comprAlg == COMPR_ALG_LIBZ)
		EndCompressorZlib(AH, cs);
#endif
	free(cs);
}