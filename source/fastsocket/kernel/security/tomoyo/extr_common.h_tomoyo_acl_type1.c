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
typedef  int u8 ;
struct tomoyo_acl_info {int type; } ;

/* Variables and functions */
 int TOMOYO_ACL_DELETED ; 

__attribute__((used)) static inline u8 tomoyo_acl_type1(struct tomoyo_acl_info *ptr)
{
	return ptr->type & ~TOMOYO_ACL_DELETED;
}