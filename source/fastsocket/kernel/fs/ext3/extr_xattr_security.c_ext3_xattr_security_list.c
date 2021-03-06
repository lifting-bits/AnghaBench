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
struct inode {int dummy; } ;

/* Variables and functions */
 char const* XATTR_SECURITY_PREFIX ; 
 size_t XATTR_SECURITY_PREFIX_LEN ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t const) ; 

__attribute__((used)) static size_t
ext3_xattr_security_list(struct inode *inode, char *list, size_t list_size,
			 const char *name, size_t name_len)
{
	const size_t prefix_len = XATTR_SECURITY_PREFIX_LEN;
	const size_t total_len = prefix_len + name_len + 1;


	if (list && total_len <= list_size) {
		memcpy(list, XATTR_SECURITY_PREFIX, prefix_len);
		memcpy(list+prefix_len, name, name_len);
		list[prefix_len + name_len] = '\0';
	}
	return total_len;
}