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
struct lcs_card {int lancmd_timeout; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 struct lcs_card* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  sscanf (char const*,char*,int*) ; 

__attribute__((used)) static ssize_t
lcs_timeout_store (struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
        struct lcs_card *card;
        int value;

	card = dev_get_drvdata(dev);

        if (!card)
                return 0;

        sscanf(buf, "%u", &value);
        /* TODO: sanity checks */
        card->lancmd_timeout = value;

        return count;

}