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
typedef  int /*<<< orphan*/  br_hash_class ;

/* Variables and functions */
 int /*<<< orphan*/  do_KAT_HMAC_bin_bin (int /*<<< orphan*/  const*,char const*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

__attribute__((used)) static void
do_KAT_HMAC_str_str(const br_hash_class *digest_class, const char *key,
	const char *data, const char *href)
{
	do_KAT_HMAC_bin_bin(digest_class, key, strlen(key),
		data, strlen(data), href);
}