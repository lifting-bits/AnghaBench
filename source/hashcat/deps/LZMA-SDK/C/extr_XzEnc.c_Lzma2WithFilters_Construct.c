#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  sb; int /*<<< orphan*/  filter; int /*<<< orphan*/ * lzma2; } ;
typedef  TYPE_1__ CLzma2WithFilters ;

/* Variables and functions */
 int /*<<< orphan*/  SbEncInStream_Construct (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SeqInFilter_Construct (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  alloc ; 

__attribute__((used)) static void Lzma2WithFilters_Construct(CLzma2WithFilters *p)
{
  p->lzma2 = NULL;
  SeqInFilter_Construct(&p->filter);

  #ifdef USE_SUBBLOCK
  SbEncInStream_Construct(&p->sb, alloc);
  #endif
}