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
struct commit_name {int dummy; } ;
typedef  int /*<<< orphan*/  git_oidmap ;
typedef  int /*<<< orphan*/  git_oid ;

/* Variables and functions */
 scalar_t__ oidmap_value_bykey (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static struct commit_name *find_commit_name(
	git_oidmap *names,
	const git_oid *peeled)
{
	return (struct commit_name *)(oidmap_value_bykey(names, peeled));
}