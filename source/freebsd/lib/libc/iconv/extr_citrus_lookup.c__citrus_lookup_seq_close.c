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
struct _citrus_lookup {int /*<<< orphan*/  (* cl_close ) (struct _citrus_lookup*) ;struct _citrus_lookup* cl_key; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct _citrus_lookup*) ; 
 int /*<<< orphan*/  stub1 (struct _citrus_lookup*) ; 

void
_citrus_lookup_seq_close(struct _citrus_lookup *cl)
{

	free(cl->cl_key);
	(*cl->cl_close)(cl);
	free(cl);
}