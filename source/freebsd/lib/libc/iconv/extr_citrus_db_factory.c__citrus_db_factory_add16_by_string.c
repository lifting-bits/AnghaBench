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
typedef  int /*<<< orphan*/  uint16_t ;
struct _region {int dummy; } ;
struct _citrus_db_factory {int dummy; } ;

/* Variables and functions */
 int _citrus_db_factory_add_by_string (struct _citrus_db_factory*,char const*,struct _region*,int) ; 
 int /*<<< orphan*/  _region_init (struct _region*,int /*<<< orphan*/ *,int) ; 
 int errno ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * malloc (int) ; 

int
_citrus_db_factory_add16_by_string(struct _citrus_db_factory *df,
    const char *key, uint16_t val)
{
	struct _region r;
	uint16_t *p;

	p = malloc(sizeof(*p));
	if (p == NULL)
		return (errno);
	*p = htons(val);
	_region_init(&r, p, 2);
	return (_citrus_db_factory_add_by_string(df, key, &r, 1));
}