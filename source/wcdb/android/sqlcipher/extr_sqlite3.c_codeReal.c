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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  Vdbe ;

/* Variables and functions */
 scalar_t__ ALWAYS (int) ; 
 int /*<<< orphan*/  OP_Real ; 
 int /*<<< orphan*/  P4_REAL ; 
 int /*<<< orphan*/  SQLITE_UTF8 ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  sqlite3AtoF (char const*,double*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3IsNaN (double) ; 
 int /*<<< orphan*/  sqlite3Strlen30 (char const*) ; 
 int /*<<< orphan*/  sqlite3VdbeAddOp4Dup8 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void codeReal(Vdbe *v, const char *z, int negateFlag, int iMem){
  if( ALWAYS(z!=0) ){
    double value;
    sqlite3AtoF(z, &value, sqlite3Strlen30(z), SQLITE_UTF8);
    assert( !sqlite3IsNaN(value) ); /* The new AtoF never returns NaN */
    if( negateFlag ) value = -value;
    sqlite3VdbeAddOp4Dup8(v, OP_Real, 0, iMem, 0, (u8*)&value, P4_REAL);
  }
}