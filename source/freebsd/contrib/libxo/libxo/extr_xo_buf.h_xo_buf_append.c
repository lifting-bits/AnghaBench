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
struct TYPE_4__ {int /*<<< orphan*/  xb_curp; } ;
typedef  TYPE_1__ xo_buffer_t ;
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,char const*,scalar_t__) ; 
 int /*<<< orphan*/  xo_buf_has_room (TYPE_1__*,scalar_t__) ; 

__attribute__((used)) static inline void
xo_buf_append (xo_buffer_t *xbp, const char *str, ssize_t len)
{
    if (str == NULL || len == 0 || !xo_buf_has_room(xbp, len))
	return;

    memcpy(xbp->xb_curp, str, len);
    xbp->xb_curp += len;
}