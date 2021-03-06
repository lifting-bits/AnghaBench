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

/* Variables and functions */
 int CPL_ERR_CONN_EXIST ; 
 int CPL_ERR_CONN_EXIST_SYNRECV ; 
 int CPL_ERR_TCAM_FULL ; 
 int CPL_ERR_TCAM_MISS ; 
 int CPL_ERR_TCAM_PARITY ; 

__attribute__((used)) static inline int act_open_has_tid(int status)
{
	return (status != CPL_ERR_TCAM_PARITY &&
		status != CPL_ERR_TCAM_MISS &&
		status != CPL_ERR_TCAM_FULL &&
		status != CPL_ERR_CONN_EXIST_SYNRECV &&
		status != CPL_ERR_CONN_EXIST);
}