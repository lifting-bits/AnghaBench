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
struct TYPE_3__ {int /*<<< orphan*/  buf; } ;
typedef  TYPE_1__ RangeObject ;

/* Variables and functions */
 int /*<<< orphan*/  PyObject_GC_Del (void*) ; 
 int /*<<< orphan*/  PyObject_GC_UnTrack (void*) ; 
 int /*<<< orphan*/  Py_XDECREF (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
RangeDestructor(RangeObject *self)
{
    PyObject_GC_UnTrack((void *)(self));
    Py_XDECREF(self->buf);
    PyObject_GC_Del((void *)(self));
}