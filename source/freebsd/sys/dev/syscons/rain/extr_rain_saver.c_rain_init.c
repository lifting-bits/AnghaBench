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
struct TYPE_3__ {int /*<<< orphan*/  vi_height; int /*<<< orphan*/  vi_width; } ;
typedef  TYPE_1__ video_info_t ;
typedef  int /*<<< orphan*/  video_adapter_t ;

/* Variables and functions */
 size_t BLUE (int) ; 
 int ENODEV ; 
 scalar_t__ INCREMENT ; 
 int /*<<< orphan*/  LOG_NOTICE ; 
 int MAX ; 
 int /*<<< orphan*/  M_VGA_CG320 ; 
 int /*<<< orphan*/  SAVER_NAME ; 
 int /*<<< orphan*/  log (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__* rain_pal ; 
 int /*<<< orphan*/  scrh ; 
 int /*<<< orphan*/  scrmode ; 
 int /*<<< orphan*/  scrw ; 
 int /*<<< orphan*/  vidd_get_info (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 

__attribute__((used)) static int
rain_init(video_adapter_t *adp)
{
	video_info_t info;
	int i;
	
	if (!vidd_get_info(adp, M_VGA_CG320, &info)) {
		scrmode = M_VGA_CG320;
	} else {
		log(LOG_NOTICE,
		    "%s: the console does not support M_VGA_CG320\n",
		    SAVER_NAME);
		return (ENODEV);
	}
	
	scrw = info.vi_width;
	scrh = info.vi_height;

	/* intialize the palette */
	for (i = 1; i < MAX; i++)
		rain_pal[BLUE(i)] = rain_pal[BLUE(i - 1)] + INCREMENT;
	
	return (0);
}