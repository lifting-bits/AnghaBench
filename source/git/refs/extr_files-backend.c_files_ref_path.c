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
struct strbuf {int dummy; } ;
struct files_ref_store {int /*<<< orphan*/  gitcommondir; int /*<<< orphan*/  gitdir; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG (char*,...) ; 
#define  REF_TYPE_MAIN_PSEUDOREF 132 
#define  REF_TYPE_NORMAL 131 
#define  REF_TYPE_OTHER_PSEUDOREF 130 
#define  REF_TYPE_PER_WORKTREE 129 
#define  REF_TYPE_PSEUDOREF 128 
 int ref_type (char const*) ; 
 int /*<<< orphan*/  skip_prefix (char const*,char*,char const**) ; 
 int /*<<< orphan*/  strbuf_addf (struct strbuf*,char*,int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static void files_ref_path(struct files_ref_store *refs,
			   struct strbuf *sb,
			   const char *refname)
{
	switch (ref_type(refname)) {
	case REF_TYPE_PER_WORKTREE:
	case REF_TYPE_PSEUDOREF:
		strbuf_addf(sb, "%s/%s", refs->gitdir, refname);
		break;
	case REF_TYPE_MAIN_PSEUDOREF:
		if (!skip_prefix(refname, "main-worktree/", &refname))
			BUG("ref %s is not a main pseudoref", refname);
		/* fallthrough */
	case REF_TYPE_OTHER_PSEUDOREF:
	case REF_TYPE_NORMAL:
		strbuf_addf(sb, "%s/%s", refs->gitcommondir, refname);
		break;
	default:
		BUG("unknown ref type %d of ref %s",
		    ref_type(refname), refname);
	}
}