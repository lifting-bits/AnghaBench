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
typedef  scalar_t__ CPUFeature ;

/* Variables and functions */
 int GetCPUInfo (scalar_t__) ; 
 scalar_t__ kAVX ; 

__attribute__((used)) static int GetCPUInfoNoAVX(CPUFeature feature) {
  if (feature == kAVX) return 0;
  return GetCPUInfo(feature);
}