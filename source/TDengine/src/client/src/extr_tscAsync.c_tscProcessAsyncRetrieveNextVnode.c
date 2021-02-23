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
typedef  int /*<<< orphan*/  TAOS_RES ;

/* Variables and functions */
 int /*<<< orphan*/  tscProcessAsyncFetchRowsProxy ; 
 int /*<<< orphan*/  tscProcessAsyncRetrieveImpl (void*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tscProcessAsyncRetrieveNextVnode(void *param, TAOS_RES *tres, int numOfRows) {
  tscProcessAsyncRetrieveImpl(param, tres, numOfRows, tscProcessAsyncFetchRowsProxy);
}