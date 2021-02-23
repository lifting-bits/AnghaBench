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
struct bhnd_nvram_sprom {int /*<<< orphan*/  data; int /*<<< orphan*/  state; } ;
struct bhnd_nvram_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bhnd_nvram_io_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bhnd_sprom_opcode_fini (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
bhnd_nvram_sprom_free(struct bhnd_nvram_data *nv)
{
	struct bhnd_nvram_sprom *sp = (struct bhnd_nvram_sprom *)nv;

	bhnd_sprom_opcode_fini(&sp->state);
	bhnd_nvram_io_free(sp->data);
}