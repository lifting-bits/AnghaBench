#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_3__ {int /*<<< orphan*/  dr; } ;
struct TYPE_4__ {int /*<<< orphan*/  u64; TYPE_1__ s; } ;
typedef  TYPE_2__ cvmx_uart_lsr_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_MIO_UARTX_LSR (int) ; 
 int /*<<< orphan*/  CVMX_MIO_UARTX_RBR (int) ; 
 int /*<<< orphan*/  cvmx_read_csr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint8_t cvmx_uart_read_byte(int uart_index)
{
    cvmx_uart_lsr_t lsrval;

    /* Spin until data is available */
    do
    {
        lsrval.u64 = cvmx_read_csr(CVMX_MIO_UARTX_LSR(uart_index));
    } while (!lsrval.s.dr);

    /* Read and return the data */
    return cvmx_read_csr(CVMX_MIO_UARTX_RBR(uart_index));
}