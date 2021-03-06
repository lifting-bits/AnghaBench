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
struct strfilter {int /*<<< orphan*/  root; } ;

/* Variables and functions */
 int /*<<< orphan*/  strfilter__delete (struct strfilter*) ; 
 int /*<<< orphan*/  strfilter_node__new (char const*,char const**) ; 
 struct strfilter* zalloc (int) ; 

struct strfilter *strfilter__new(const char *rules, const char **err)
{
	struct strfilter *ret = zalloc(sizeof(struct strfilter));
	const char *ep = NULL;

	if (ret)
		ret->root = strfilter_node__new(rules, &ep);

	if (!ret || !ret->root || *ep != '\0') {
		if (err)
			*err = ep;
		strfilter__delete(ret);
		ret = NULL;
	}

	return ret;
}