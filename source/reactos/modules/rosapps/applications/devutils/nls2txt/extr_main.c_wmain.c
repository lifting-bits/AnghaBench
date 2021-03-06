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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int INT ;

/* Variables and functions */
 int /*<<< orphan*/  BestFit_FromNLS (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

INT wmain(INT argc, WCHAR* argv[])
{
    if (argc != 3)
        return 1;

    if (!BestFit_FromNLS(argv[1], argv[2]))
        return 1;

    return 0;
}