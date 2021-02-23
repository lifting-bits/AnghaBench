#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/ * buf; } ;
struct TYPE_7__ {TYPE_2__* current; } ;
typedef  TYPE_1__ FORM ;
typedef  int /*<<< orphan*/  FIELD_CELL ;
typedef  TYPE_2__ FIELD ;

/* Variables and functions */
 int /*<<< orphan*/  Adjust_Cursor_Position (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * After_End_Of_Data (int /*<<< orphan*/ *,int) ; 
 int Buffer_Length (TYPE_2__*) ; 
 int /*<<< orphan*/  E_OK ; 
 int /*<<< orphan*/  Synchronize_Buffer (TYPE_1__*) ; 
 int /*<<< orphan*/  T (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  T_CALLED (char*) ; 
 int /*<<< orphan*/  returnCode (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
IFN_End_Of_Field(FORM *form)
{
  FIELD *field = form->current;
  FIELD_CELL *pos;

  T((T_CALLED("IFN_End_Of_Field(%p)"), (void *)form));
  Synchronize_Buffer(form);
  pos = After_End_Of_Data(field->buf, Buffer_Length(field));
  if (pos == (field->buf + Buffer_Length(field)))
    pos--;
  Adjust_Cursor_Position(form, pos);
  returnCode(E_OK);
}