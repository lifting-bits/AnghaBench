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
 char* LSAPI_GetHeader_r (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  g_req ; 

__attribute__((used)) static inline char * LSAPI_GetHeader( int headerIndex )
{   return LSAPI_GetHeader_r( &g_req, headerIndex );        }