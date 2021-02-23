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
struct mbuf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  m_freem (struct mbuf*) ; 

__attribute__((used)) static inline void safe_m_freem(struct mbuf **ppMbuf) {
	if (*ppMbuf != NULL) {
		m_freem(*ppMbuf);
		*ppMbuf = NULL;
	}
}