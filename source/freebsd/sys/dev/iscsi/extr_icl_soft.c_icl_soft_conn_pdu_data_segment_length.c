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
struct icl_pdu {int dummy; } ;
struct icl_conn {int dummy; } ;

/* Variables and functions */
 size_t icl_pdu_data_segment_length (struct icl_pdu const*) ; 

size_t
icl_soft_conn_pdu_data_segment_length(struct icl_conn *ic,
    const struct icl_pdu *request)
{

	return (icl_pdu_data_segment_length(request));
}