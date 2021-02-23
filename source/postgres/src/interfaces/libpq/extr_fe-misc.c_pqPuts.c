#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ Pfdebug; } ;
typedef  TYPE_1__ PGconn ;

/* Variables and functions */
 int EOF ; 
 int /*<<< orphan*/  fprintf (scalar_t__,char*,char const*) ; 
 scalar_t__ pqPutMsgBytes (char const*,scalar_t__,TYPE_1__*) ; 
 scalar_t__ strlen (char const*) ; 

int
pqPuts(const char *s, PGconn *conn)
{
	if (pqPutMsgBytes(s, strlen(s) + 1, conn))
		return EOF;

	if (conn->Pfdebug)
		fprintf(conn->Pfdebug, "To backend> \"%s\"\n", s);

	return 0;
}