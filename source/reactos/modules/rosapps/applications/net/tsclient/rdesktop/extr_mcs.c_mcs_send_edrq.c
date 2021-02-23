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
typedef  int /*<<< orphan*/ * STREAM ;
typedef  int /*<<< orphan*/  RDPCLIENT ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  False ; 
 int MCS_EDRQ ; 
 int /*<<< orphan*/ * iso_init (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  iso_send (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  out_uint16_be (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  out_uint8 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  s_mark_end (int /*<<< orphan*/ *) ; 

__attribute__((used)) static BOOL
mcs_send_edrq(RDPCLIENT * This)
{
	STREAM s;

	s = iso_init(This, 5);

	if(s == NULL)
		return False;

	out_uint8(s, (MCS_EDRQ << 2));
	out_uint16_be(s, 1);	/* height */
	out_uint16_be(s, 1);	/* interval */

	s_mark_end(s);
	return iso_send(This, s);
}