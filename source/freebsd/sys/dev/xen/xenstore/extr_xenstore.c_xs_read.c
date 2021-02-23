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
typedef  int /*<<< orphan*/  u_int ;
struct xs_transaction {int dummy; } ;
struct sbuf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  XS_READ ; 
 int /*<<< orphan*/  sbuf_data (struct sbuf*) ; 
 int /*<<< orphan*/  sbuf_delete (struct sbuf*) ; 
 struct sbuf* xs_join (char const*,char const*) ; 
 int xs_single (struct xs_transaction,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void**) ; 

int
xs_read(struct xs_transaction t, const char *dir, const char *node,
    u_int *len, void **result)
{
	struct sbuf *path;
	void *ret;
	int error;

	path = xs_join(dir, node);
	error = xs_single(t, XS_READ, sbuf_data(path), len, &ret);
	sbuf_delete(path);
	if (error)
		return (error);
	*result = ret;
	return (0);
}