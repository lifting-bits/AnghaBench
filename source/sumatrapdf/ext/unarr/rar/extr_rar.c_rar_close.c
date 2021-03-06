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
struct TYPE_3__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int /*<<< orphan*/  uncomp; TYPE_1__ entry; } ;
typedef  TYPE_2__ ar_archive_rar ;
typedef  int /*<<< orphan*/  ar_archive ;

/* Variables and functions */
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rar_clear_uncompress (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void rar_close(ar_archive *ar)
{
    ar_archive_rar *rar = (ar_archive_rar *)ar;
    free(rar->entry.name);
    rar_clear_uncompress(&rar->uncomp);
}