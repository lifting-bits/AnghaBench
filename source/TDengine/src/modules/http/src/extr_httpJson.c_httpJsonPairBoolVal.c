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
typedef  int /*<<< orphan*/  JsonBuf ;

/* Variables and functions */
 int /*<<< orphan*/  httpJsonBool (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  httpJsonPairHead (int /*<<< orphan*/ *,char*,int) ; 

void httpJsonPairBoolVal(JsonBuf* buf, char* name, int nNameLen, int num) {
  httpJsonPairHead(buf, name, nNameLen);
  httpJsonBool(buf, num);
}