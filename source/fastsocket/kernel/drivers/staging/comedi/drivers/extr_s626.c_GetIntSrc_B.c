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
typedef  int uint16_t ;
struct enc_private {int /*<<< orphan*/  MyCRB; } ;
struct comedi_device {int dummy; } ;

/* Variables and functions */
 int CRBBIT_INTSRC_B ; 
 int DEBIread (struct comedi_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint16_t GetIntSrc_B(struct comedi_device *dev, struct enc_private *k)
{
	return (DEBIread(dev, k->MyCRB) >> CRBBIT_INTSRC_B) & 3;
}