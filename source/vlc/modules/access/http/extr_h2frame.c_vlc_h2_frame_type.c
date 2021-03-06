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
typedef  int /*<<< orphan*/  uint_fast8_t ;
struct vlc_h2_frame {int /*<<< orphan*/ * data; } ;

/* Variables and functions */

__attribute__((used)) static uint_fast8_t vlc_h2_frame_type(const struct vlc_h2_frame *f)
{
    return f->data[3];
}