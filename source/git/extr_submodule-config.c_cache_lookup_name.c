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
struct submodule_entry {struct submodule* config; int /*<<< orphan*/  ent; } ;
struct submodule_cache {int /*<<< orphan*/  for_name; } ;
struct submodule {char const* name; int /*<<< orphan*/  gitmodules_oid; } ;
struct object_id {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ent ; 
 unsigned int hash_oid_string (struct object_id const*,char const*) ; 
 int /*<<< orphan*/  hashmap_entry_init (int /*<<< orphan*/ *,unsigned int) ; 
 struct submodule_entry* hashmap_get_entry (int /*<<< orphan*/ *,struct submodule_entry*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  oidcpy (int /*<<< orphan*/ *,struct object_id const*) ; 

__attribute__((used)) static struct submodule *cache_lookup_name(struct submodule_cache *cache,
		const struct object_id *gitmodules_oid, const char *name)
{
	struct submodule_entry *entry;
	unsigned int hash = hash_oid_string(gitmodules_oid, name);
	struct submodule_entry key;
	struct submodule key_config;

	oidcpy(&key_config.gitmodules_oid, gitmodules_oid);
	key_config.name = name;

	hashmap_entry_init(&key.ent, hash);
	key.config = &key_config;

	entry = hashmap_get_entry(&cache->for_name, &key, ent, NULL);
	if (entry)
		return entry->config;
	return NULL;
}