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
struct thread {int dummy; } ;
struct extattr_get_link_args {int /*<<< orphan*/  nbytes; int /*<<< orphan*/  data; int /*<<< orphan*/  attrname; int /*<<< orphan*/  attrnamespace; int /*<<< orphan*/  path; } ;

/* Variables and functions */
 int /*<<< orphan*/  NOFOLLOW ; 
 int kern_extattr_get_path (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
sys_extattr_get_link(struct thread *td, struct extattr_get_link_args *uap)
{
	return (kern_extattr_get_path(td, uap->path, uap->attrnamespace,
	    uap->attrname, uap->data, uap->nbytes, NOFOLLOW));
}