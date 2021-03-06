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
struct pmcraid_instance {int current_log_level; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 struct Scsi_Host* class_to_shost (struct device*) ; 
 scalar_t__ kstrtou8 (char const*,int,int*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

__attribute__((used)) static ssize_t pmcraid_store_log_level(
	struct device *dev,
	struct device_attribute *attr,
	const char *buf,
	size_t count
)
{
	struct Scsi_Host *shost;
	struct pmcraid_instance *pinstance;
	u8 val;

	if (kstrtou8(buf, 10, &val))
		return -EINVAL;
	/* log-level should be from 0 to 2 */
	if (val > 2)
		return -EINVAL;

	shost = class_to_shost(dev);
	pinstance = (struct pmcraid_instance *)shost->hostdata;
	pinstance->current_log_level = val;

	return strlen(buf);
}