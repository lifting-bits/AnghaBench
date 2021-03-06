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
 int /*<<< orphan*/  crc64Hash ; 
 int /*<<< orphan*/  printf (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sha1Hash ; 
 int /*<<< orphan*/  testHashingFunction (int /*<<< orphan*/ ) ; 

int main(void) {
    printf("SHA1 : %lu\n", testHashingFunction(sha1Hash));
    printf("CRC64: %lu\n", testHashingFunction(crc64Hash));
    return 0;
}