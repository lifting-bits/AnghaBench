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
typedef  int /*<<< orphan*/  Con ;

/* Variables and functions */
 int /*<<< orphan*/  CF_OUTPUT ; 
 int /*<<< orphan*/  LOG (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * con_get_fullscreen_con (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * con_get_output (int /*<<< orphan*/ *) ; 

bool workspace_is_visible(Con *ws) {
    Con *output = con_get_output(ws);
    if (output == NULL)
        return false;
    Con *fs = con_get_fullscreen_con(output, CF_OUTPUT);
    LOG("workspace visible? fs = %p, ws = %p\n", fs, ws);
    return (fs == ws);
}