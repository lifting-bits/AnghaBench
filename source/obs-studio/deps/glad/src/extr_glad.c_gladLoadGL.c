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

/* Variables and functions */
 int /*<<< orphan*/  close_gl () ; 
 int /*<<< orphan*/  get_proc ; 
 int /*<<< orphan*/  gladLoadGLLoader (int /*<<< orphan*/ *) ; 
 scalar_t__ open_gl () ; 

int gladLoadGL(void) {
    if(open_gl()) {
        gladLoadGLLoader(&get_proc);
        close_gl();
        return 1;
    }
    return 0;
}