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
struct nn_xrespondent {int /*<<< orphan*/  inpipes; int /*<<< orphan*/  outpipes; int /*<<< orphan*/  next_key; int /*<<< orphan*/  sockbase; } ;
struct nn_sockbase_vfptr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nn_fq_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_hash_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_random_generate (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  nn_sockbase_init (int /*<<< orphan*/ *,struct nn_sockbase_vfptr const*,void*) ; 

void nn_xrespondent_init (struct nn_xrespondent *self,
    const struct nn_sockbase_vfptr *vfptr, void *hint)
{
    nn_sockbase_init (&self->sockbase, vfptr, hint);

    /*  Pipes IDs should be random.  See RFC for info. */
    nn_random_generate (&self->next_key, sizeof (self->next_key));
    nn_hash_init (&self->outpipes);
    nn_fq_init (&self->inpipes);
}