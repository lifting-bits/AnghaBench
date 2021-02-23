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
typedef  int /*<<< orphan*/  (* httpJsonBuilder ) (int /*<<< orphan*/ *,void*) ;
typedef  int /*<<< orphan*/  JsonBuf ;

/* Variables and functions */
 int /*<<< orphan*/  JsonObjEnd ; 
 int /*<<< orphan*/  JsonObjStt ; 
 int /*<<< orphan*/  httpJsonItemToken (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  httpJsonToken (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,void*) ; 

void httpJsonObject(JsonBuf* buf, httpJsonBuilder fnBuilder, void* dsHandle) {
  httpJsonItemToken(buf);
  httpJsonToken(buf, JsonObjStt);
  (*fnBuilder)(buf, dsHandle);
  httpJsonToken(buf, JsonObjEnd);
}