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
typedef  scalar_t__ u_int16_t ;
typedef  int /*<<< orphan*/  u_char ;
typedef  int /*<<< orphan*/  token_t ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_STRING (int /*<<< orphan*/ *,char const*,scalar_t__) ; 
 int /*<<< orphan*/  ADD_U_CHAR (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ADD_U_INT16 (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  AUT_PATH ; 
 int /*<<< orphan*/  GET_TOKEN_AREA (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ strlen (char const*) ; 

token_t *
au_to_path(const char *text)
{
	token_t *t;
	u_char *dptr = NULL;
	u_int16_t textlen;

	textlen = strlen(text);
	textlen += 1;

	GET_TOKEN_AREA(t, dptr, sizeof(u_char) + sizeof(u_int16_t) + textlen);
	if (t == NULL)
		return (NULL);

	ADD_U_CHAR(dptr, AUT_PATH);
	ADD_U_INT16(dptr, textlen);
	ADD_STRING(dptr, text, textlen);

	return (t);
}