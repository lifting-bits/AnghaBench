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
struct parse {scalar_t__ ssize; scalar_t__ slen; scalar_t__ strip; scalar_t__ stripdata; } ;
typedef  scalar_t__ sopno ;
typedef  int /*<<< orphan*/  sop ;
typedef  int /*<<< orphan*/  RCHAR_T ;

/* Variables and functions */
 scalar_t__ HERE () ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  enlarge (struct parse*,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (char*,char*,size_t) ; 

__attribute__((used)) static sopno			/* start of duplicate */
dupl(struct parse *p,
    sopno start,		/* from here */
    sopno finish)		/* to this less one */
{
	sopno ret = HERE();
	sopno len = finish - start;

	assert(finish >= start);
	if (len == 0)
		return(ret);
	if (!enlarge(p, p->ssize + len))	/* this many unexpected additions */
		return ret;
	assert(p->ssize >= p->slen + len);
	(void) memcpy((char *)(p->strip + p->slen),
		(char *)(p->strip + start), (size_t)len*sizeof(sop));
	(void) memcpy((char *)(p->stripdata + p->slen),
		(char *)(p->stripdata + start), (size_t)len*sizeof(RCHAR_T));
	p->slen += len;
	return(ret);
}