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
struct label {int dummy; } ;
struct ipq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  COUNTER_INC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LABEL_CHECK (struct label*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAGIC_IPQ ; 
 int /*<<< orphan*/  MAGIC_MBUF ; 
 int /*<<< orphan*/  ipq_reassemble ; 

__attribute__((used)) static void
test_ipq_reassemble(struct ipq *q, struct label *qlabel, struct mbuf *m,
   struct label *mlabel)
{

	LABEL_CHECK(qlabel, MAGIC_IPQ);
	LABEL_CHECK(mlabel, MAGIC_MBUF);
	COUNTER_INC(ipq_reassemble);
}