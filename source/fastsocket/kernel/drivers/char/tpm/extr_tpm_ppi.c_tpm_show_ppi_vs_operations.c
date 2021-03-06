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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PPI_VS_REQ_END ; 
 int /*<<< orphan*/  PPI_VS_REQ_START ; 
 int /*<<< orphan*/  show_ppi_operations (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t tpm_show_ppi_vs_operations(struct device *dev,
					  struct device_attribute *attr,
					  char *buf)
{
	return show_ppi_operations(buf, PPI_VS_REQ_START, PPI_VS_REQ_END);
}