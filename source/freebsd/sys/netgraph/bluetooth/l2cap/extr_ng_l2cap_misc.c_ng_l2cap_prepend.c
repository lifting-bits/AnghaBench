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
struct mbuf {int m_len; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_NOWAIT ; 
 int /*<<< orphan*/  M_PREPEND (struct mbuf*,int,int /*<<< orphan*/ ) ; 
 struct mbuf* m_pullup (struct mbuf*,int) ; 

struct mbuf *
ng_l2cap_prepend(struct mbuf *m, int size)
{
	M_PREPEND(m, size, M_NOWAIT);
	if (m == NULL || (m->m_len < size && (m = m_pullup(m, size)) == NULL))
		return (NULL);

	return (m);
}