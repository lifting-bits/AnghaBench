#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * signature; int /*<<< orphan*/ * taos; int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ HttpSession ;

/* Variables and functions */
 int /*<<< orphan*/  httpTrace (char*,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  taos_close (int /*<<< orphan*/ *) ; 

void httpResetSession(char *session) {
  HttpSession *pSession = (HttpSession *)session;
  httpTrace("close session:%p:%s:%p", pSession, pSession->id, pSession->taos);
  if (pSession->taos != NULL) {
    taos_close(pSession->taos);
    pSession->taos = NULL;
  }
  pSession->signature = NULL;
}