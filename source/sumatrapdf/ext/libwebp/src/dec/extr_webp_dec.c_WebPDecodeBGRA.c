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

/* Variables and functions */
 int /*<<< orphan*/ * Decode (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,size_t,int*,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MODE_BGRA ; 

uint8_t* WebPDecodeBGRA(const uint8_t* data, size_t data_size,
                        int* width, int* height) {
  return Decode(MODE_BGRA, data, data_size, width, height, NULL);
}