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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_SYNCWS ; 
 int /*<<< orphan*/  cvmx_atomic_fetch_and_add32_nosync (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int32_t cvmx_atomic_fetch_and_add32(int32_t *ptr, int32_t incr)
{
    uint32_t ret;
    CVMX_SYNCWS;
    ret = cvmx_atomic_fetch_and_add32_nosync(ptr, incr);
    CVMX_SYNCWS;
    return ret;
}