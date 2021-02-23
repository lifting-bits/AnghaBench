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
typedef  int /*<<< orphan*/  Fts5ExprPhrase ;

/* Variables and functions */
 int /*<<< orphan*/  fts5ExprPhraseFree (int /*<<< orphan*/ *) ; 

void sqlite3Fts5ParsePhraseFree(Fts5ExprPhrase *pPhrase){
  fts5ExprPhraseFree(pPhrase);
}