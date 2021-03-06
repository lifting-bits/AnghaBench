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
typedef  int /*<<< orphan*/  int32_t ;
typedef  int /*<<< orphan*/  i ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 size_t fwrite (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *) ; 

size_t write_int32(FILE* fp, int32_t i) {
    return fwrite(&i, sizeof(i), 1, fp);
}