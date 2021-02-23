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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  bhnd_nvram_plist ;

/* Variables and functions */
 int /*<<< orphan*/  BHND_NVRAM_TYPE_UINT8 ; 
 int bhnd_nvram_plist_get_encoded (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

int
bhnd_nvram_plist_get_uint8(bhnd_nvram_plist *plist, const char *name,
    uint8_t *val)
{
	return (bhnd_nvram_plist_get_encoded(plist, name, val, sizeof(*val),
	    BHND_NVRAM_TYPE_UINT8));
}