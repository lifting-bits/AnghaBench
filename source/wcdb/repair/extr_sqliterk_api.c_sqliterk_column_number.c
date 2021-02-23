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
typedef  int /*<<< orphan*/  sqliterk_column ;

/* Variables and functions */
 int /*<<< orphan*/  sqliterkColumnGetValues (int /*<<< orphan*/ *) ; 
 double sqliterkValuesGetNumber (int /*<<< orphan*/ ,int) ; 

double sqliterk_column_number(sqliterk_column *column, int index)
{
    return sqliterkValuesGetNumber(sqliterkColumnGetValues(column), index);
}