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
typedef  int /*<<< orphan*/  RETSIGTYPE ;

/* Variables and functions */
 int /*<<< orphan*/  kcm_context ; 
 int /*<<< orphan*/  kcm_debug_ccache (int /*<<< orphan*/ ) ; 

__attribute__((used)) static RETSIGTYPE
sigusr1(int sig)
{
    kcm_debug_ccache(kcm_context);
}