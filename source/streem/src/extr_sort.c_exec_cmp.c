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
typedef  int /*<<< orphan*/  strm_value ;
typedef  int /*<<< orphan*/  strm_stream ;
typedef  int /*<<< orphan*/  strm_int ;

/* Variables and functions */
 int STRM_OK ; 
 int /*<<< orphan*/  strm_cmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strm_get_args (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strm_int_value (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
exec_cmp(strm_stream* strm, int argc, strm_value* args, strm_value* ret)
{
  strm_int cmp;
  strm_value x, y;

  strm_get_args(strm, argc, args, "vv", &x, &y);
  cmp = strm_cmp(x, y);
  *ret = strm_int_value(cmp);
  return STRM_OK;
}