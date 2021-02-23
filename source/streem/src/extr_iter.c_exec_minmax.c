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
struct minmax_data {int min; void* func; void* data; scalar_t__ num; int /*<<< orphan*/  start; } ;
typedef  void* strm_value ;
typedef  int /*<<< orphan*/  strm_stream ;

/* Variables and functions */
 int STRM_NG ; 
 int STRM_OK ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  iter_minmax ; 
 struct minmax_data* malloc (int) ; 
 int /*<<< orphan*/  minmax_finish ; 
 int /*<<< orphan*/  strm_filter ; 
 int /*<<< orphan*/  strm_get_args (int /*<<< orphan*/ *,int,void**,char*,void**) ; 
 void* strm_nil_value () ; 
 int /*<<< orphan*/  strm_stream_new (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 void* strm_stream_value (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
exec_minmax(strm_stream* strm, int argc, strm_value* args, strm_value* ret, int min)
{
  struct minmax_data* d;
  strm_value func = strm_nil_value();

  strm_get_args(strm, argc, args, "|v", &func);
  d = malloc(sizeof(*d));
  if (!d) return STRM_NG;
  d->start = TRUE;
  d->min = min;
  d->num = 0;
  d->data = strm_nil_value();
  d->func = func;
  *ret = strm_stream_value(strm_stream_new(strm_filter, iter_minmax, minmax_finish, (void*)d));
  return STRM_OK;
}