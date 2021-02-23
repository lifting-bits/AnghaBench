#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {char* datatype; int /*<<< orphan*/  lbl; } ;
typedef  TYPE_1__ GDefMetric ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  OVERALL_BANDWIDTH ; 
 int /*<<< orphan*/  T_BW ; 
 int /*<<< orphan*/  fpclose_obj (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  fpopen_obj_attr (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  print_def_metric (int /*<<< orphan*/ *,TYPE_1__,int) ; 

__attribute__((used)) static void
print_def_overall_bandwidth (FILE * fp, int sp)
{
  GDefMetric def = {
    .lbl = T_BW,
    .datatype = "bytes",
  };
  fpopen_obj_attr (fp, OVERALL_BANDWIDTH, sp);
  print_def_metric (fp, def, sp);
  fpclose_obj (fp, sp, 1);
}