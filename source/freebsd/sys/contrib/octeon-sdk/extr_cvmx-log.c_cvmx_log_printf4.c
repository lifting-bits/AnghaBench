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
typedef  int /*<<< orphan*/  uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  CAST64 (char const*) ; 
 int /*<<< orphan*/  CVMX_LOG_TYPE_PRINTF ; 
 int /*<<< orphan*/  __cvmx_log_build_header (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  __cvmx_log_write (int /*<<< orphan*/ ) ; 

void cvmx_log_printf4(const char *format, uint64_t number1, uint64_t number2, uint64_t number3, uint64_t number4)
{
    __cvmx_log_write(__cvmx_log_build_header(CVMX_LOG_TYPE_PRINTF, 5));
    __cvmx_log_write(CAST64(format));
    __cvmx_log_write(number1);
    __cvmx_log_write(number2);
    __cvmx_log_write(number3);
    __cvmx_log_write(number4);
}