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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  hb_stream_t ;

/* Variables and functions */
 int isIframe (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static int ts_isIframe( hb_stream_t *stream, const uint8_t *buf, int adapt_len )
{
    return isIframe( stream, buf + 13 + adapt_len, 188 - ( 13 + adapt_len ) );
}