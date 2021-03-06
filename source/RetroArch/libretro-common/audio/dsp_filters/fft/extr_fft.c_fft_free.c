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
struct TYPE_4__ {struct TYPE_4__* phase_lut; struct TYPE_4__* bitinverse_buffer; struct TYPE_4__* interleave_buffer; } ;
typedef  TYPE_1__ fft_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 

void fft_free(fft_t *fft)
{
   if (!fft)
      return;

   free(fft->interleave_buffer);
   free(fft->bitinverse_buffer);
   free(fft->phase_lut);
   free(fft);
}