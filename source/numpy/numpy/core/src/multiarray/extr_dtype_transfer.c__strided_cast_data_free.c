#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  aop; int /*<<< orphan*/  aip; } ;
typedef  TYPE_1__ _strided_cast_data ;
typedef  int /*<<< orphan*/  NpyAuxData ;

/* Variables and functions */
 int /*<<< orphan*/  PyArray_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Py_DECREF (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void _strided_cast_data_free(NpyAuxData *data)
{
    _strided_cast_data *d = (_strided_cast_data *)data;
    Py_DECREF(d->aip);
    Py_DECREF(d->aop);
    PyArray_free(data);
}