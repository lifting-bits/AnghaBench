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
typedef  int /*<<< orphan*/  bhnd_nvram_type ;
typedef  int /*<<< orphan*/  bhnd_nvram_prop ;
typedef  int /*<<< orphan*/  bhnd_nvram_plist ;

/* Variables and functions */
 int ENOMEM ; 
 int bhnd_nvram_plist_replace (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * bhnd_nvram_prop_bytes_new (char const*,void const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bhnd_nvram_prop_release (int /*<<< orphan*/ *) ; 

int
bhnd_nvram_plist_replace_bytes(bhnd_nvram_plist *plist, const char *name,
    const void *inp, size_t ilen, bhnd_nvram_type itype)
{
	bhnd_nvram_prop	*prop;
	int		 error;

	if ((prop = bhnd_nvram_prop_bytes_new(name, inp, ilen, itype)) == NULL)
		return (ENOMEM);

	error = bhnd_nvram_plist_replace(plist, prop);
	bhnd_nvram_prop_release(prop);

	return (error);
}