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
typedef  int /*<<< orphan*/  int64 ;
typedef  int int32 ;
typedef  int /*<<< orphan*/  int16 ;
typedef  int /*<<< orphan*/  Datum ;
typedef  int /*<<< orphan*/  Const ;

/* Variables and functions */
 int /*<<< orphan*/  INT8OID ; 
 int /*<<< orphan*/  Int64GetDatum (int /*<<< orphan*/ ) ; 
 int get_typcollation (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_typlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * makeConst (int /*<<< orphan*/ ,int const,int const,int /*<<< orphan*/  const,int /*<<< orphan*/ ,int const,int const) ; 

__attribute__((used)) static Const *
MakeIntegerConstInt64(int64 integerValue)
{
	const int typeCollationId = get_typcollation(INT8OID);
	const int16 typeLength = get_typlen(INT8OID);
	const int32 typeModifier = -1;
	const bool typeIsNull = false;
	const bool typePassByValue = true;

	Datum integer64Datum = Int64GetDatum(integerValue);
	Const *integer64Const = makeConst(INT8OID, typeModifier, typeCollationId, typeLength,
									  integer64Datum, typeIsNull, typePassByValue);

	return integer64Const;
}