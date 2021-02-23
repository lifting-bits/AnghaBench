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
typedef  int uch ;
struct parse {char* next; char* end; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int othercase (int) ; 
 int /*<<< orphan*/  p_bracket (struct parse*) ; 

__attribute__((used)) static void
bothcases(struct parse *p, int ch)
{
	char *oldnext = p->next;
	char *oldend = p->end;
	char bracket[3];

	ch = (uch)ch;
	assert(othercase(ch) != ch);	/* p_bracket() would recurse */
	p->next = bracket;
	p->end = bracket+2;
	bracket[0] = ch;
	bracket[1] = ']';
	bracket[2] = '\0';
	p_bracket(p);
	assert(p->next == bracket+2);
	p->next = oldnext;
	p->end = oldend;
}