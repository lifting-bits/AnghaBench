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
typedef  int /*<<< orphan*/  absname ;

/* Variables and functions */
 int PATH_MAX ; 
 int /*<<< orphan*/  ctx ; 
 int /*<<< orphan*/  doc ; 
 int /*<<< orphan*/  fz_document_supports_accelerator (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fz_save_accelerator (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  get_accelerator_filename (char*,int) ; 

__attribute__((used)) static void save_accelerator(void)
{
	char absname[PATH_MAX];

	if (!doc)
		return;
	if (!fz_document_supports_accelerator(ctx, doc))
		return;
	if (!get_accelerator_filename(absname, sizeof(absname)))
		return;

	fz_save_accelerator(ctx, doc, absname);
}