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
struct TYPE_2__ {int /*<<< orphan*/  bitwise_and; } ;
typedef  int /*<<< orphan*/  PyObject ;
typedef  int /*<<< orphan*/  PyArrayObject ;

/* Variables and functions */
 int /*<<< orphan*/  BINOP_GIVE_UP_IF_NEEDED (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ * (*) (int /*<<< orphan*/ *,int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/ * PyArray_GenericBinaryFunction (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  array_inplace_bitwise_and ; 
 TYPE_1__ n_ops ; 
 int /*<<< orphan*/  nb_and ; 
 scalar_t__ try_binary_elide (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int) ; 

__attribute__((used)) static PyObject *
array_bitwise_and(PyArrayObject *m1, PyObject *m2)
{
    PyObject *res;

    BINOP_GIVE_UP_IF_NEEDED(m1, m2, nb_and, array_bitwise_and);
    if (try_binary_elide(m1, m2, &array_inplace_bitwise_and, &res, 1)) {
        return res;
    }
    return PyArray_GenericBinaryFunction(m1, m2, n_ops.bitwise_and);
}