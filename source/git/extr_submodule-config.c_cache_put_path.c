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
struct submodule_entry {int /*<<< orphan*/  ent; struct submodule* config; } ;
struct submodule_cache {int /*<<< orphan*/  for_path; } ;
struct submodule {int /*<<< orphan*/  path; int /*<<< orphan*/  gitmodules_oid; } ;

/* Variables and functions */
 unsigned int hash_oid_string (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hashmap_entry_init (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  hashmap_put (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct submodule_entry* xmalloc (int) ; 

__attribute__((used)) static void cache_put_path(struct submodule_cache *cache,
			   struct submodule *submodule)
{
	unsigned int hash = hash_oid_string(&submodule->gitmodules_oid,
					    submodule->path);
	struct submodule_entry *e = xmalloc(sizeof(*e));
	hashmap_entry_init(&e->ent, hash);
	e->config = submodule;
	hashmap_put(&cache->for_path, &e->ent);
}