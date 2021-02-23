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
struct TYPE_3__ {scalar_t__ type; char* string; } ;
typedef  TYPE_1__ token_t ;
typedef  int /*<<< orphan*/  source_t ;
typedef  int qboolean ;
typedef  int /*<<< orphan*/  fielddef_t ;

/* Variables and functions */
 int /*<<< orphan*/  PC_ExpectAnyToken (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  PC_UnreadLastToken (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReadNumber (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  StripSingleQuotes (char*) ; 
 scalar_t__ TT_LITERAL ; 

qboolean ReadChar(source_t *source, fielddef_t *fd, void *p)
{
	token_t token;

	if (!PC_ExpectAnyToken(source, &token)) return 0;

	//take literals into account
	if (token.type == TT_LITERAL)
	{
		StripSingleQuotes(token.string);
		*(char *) p = token.string[0];
	} //end if
	else
	{
		PC_UnreadLastToken(source);
		if (!ReadNumber(source, fd, p)) return 0;
	} //end if
	return 1;
}