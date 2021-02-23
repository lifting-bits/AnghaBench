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
struct wlp_wss_attribute {int /*<<< orphan*/  (* store ) (struct wlp_wss*,char const*,size_t) ;} ;
struct wlp_wss {int dummy; } ;
struct kobject {int dummy; } ;
struct attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 struct wlp_wss_attribute* attr_to_wlp_wss_attr (struct attribute*) ; 
 struct wlp_wss* kobj_to_wlp_wss (struct kobject*) ; 
 int /*<<< orphan*/  stub1 (struct wlp_wss*,char const*,size_t) ; 

__attribute__((used)) static
ssize_t wlp_wss_attr_store(struct kobject *kobj, struct attribute *attr,
			   const char *buf, size_t count)
{
	struct wlp_wss_attribute *wss_attr = attr_to_wlp_wss_attr(attr);
	struct wlp_wss *wss = kobj_to_wlp_wss(kobj);
	ssize_t ret = -EIO;

	if (wss_attr->store)
		ret = wss_attr->store(wss, buf, count);
	return ret;
}