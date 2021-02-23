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
typedef  int /*<<< orphan*/  Datum ;
typedef  int /*<<< orphan*/  ArrayType ;

/* Variables and functions */
 int /*<<< orphan*/ * DatumGetArrayTypeP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PointerGetDatum (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  array_set_element (int /*<<< orphan*/ ,int,int*,int /*<<< orphan*/ ,int,int,int,int,char) ; 

ArrayType *
array_set(ArrayType *array, int nSubscripts, int *indx,
		  Datum dataValue, bool isNull,
		  int arraytyplen, int elmlen, bool elmbyval, char elmalign)
{
	return DatumGetArrayTypeP(array_set_element(PointerGetDatum(array),
												nSubscripts, indx,
												dataValue, isNull,
												arraytyplen,
												elmlen, elmbyval, elmalign));
}