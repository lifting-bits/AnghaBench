#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_3__* children; } ;
typedef  TYPE_2__ svn_skel_t ;
typedef  int /*<<< orphan*/  svn_boolean_t ;
struct TYPE_8__ {TYPE_1__* next; } ;
struct TYPE_6__ {scalar_t__ is_atom; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int svn_skel__list_length (TYPE_2__*) ; 
 scalar_t__ svn_skel__matches_atom (TYPE_3__*,char*) ; 

__attribute__((used)) static svn_boolean_t
is_valid_checksum_skel(svn_skel_t *skel)
{
  if (svn_skel__list_length(skel) != 2)
    return FALSE;

  if (svn_skel__matches_atom(skel->children, "md5")
      && skel->children->next->is_atom)
    return TRUE;

  if (svn_skel__matches_atom(skel->children, "sha1")
      && skel->children->next->is_atom)
    return TRUE;

  return FALSE;
}