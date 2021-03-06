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
typedef  int /*<<< orphan*/  u_int32_t ;
typedef  int /*<<< orphan*/  u_char ;
typedef  int /*<<< orphan*/  token_t ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_MEM (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  ADD_U_CHAR (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ADD_U_INT32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  AUT_EXEC_ARGS ; 
 int /*<<< orphan*/  GET_TOKEN_AREA (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int strlen (char const*) ; 

token_t *
au_to_exec_args(char **argv)
{
	token_t *t;
	u_char *dptr = NULL;
	const char *nextarg;
	int i, count = 0;
	size_t totlen = 0;

	nextarg = *argv;

	while (nextarg != NULL) {
		int nextlen;

		nextlen = strlen(nextarg);
		totlen += nextlen + 1;
		count++;
		nextarg = *(argv + count);
	}

	GET_TOKEN_AREA(t, dptr, sizeof(u_char) + sizeof(u_int32_t) + totlen);
	if (t == NULL)
		return (NULL);

	ADD_U_CHAR(dptr, AUT_EXEC_ARGS);
	ADD_U_INT32(dptr, count);

	for (i = 0; i < count; i++) {
		nextarg = *(argv + i);
		ADD_MEM(dptr, nextarg, strlen(nextarg) + 1);
	}

	return (t);
}