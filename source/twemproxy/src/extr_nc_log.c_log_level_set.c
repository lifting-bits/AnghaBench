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
struct logger {int /*<<< orphan*/  level; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_EMERG ; 
 int /*<<< orphan*/  LOG_PVERB ; 
 int /*<<< orphan*/  MAX (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MIN (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  loga (char*,int /*<<< orphan*/ ) ; 
 struct logger logger ; 

void
log_level_set(int level)
{
    struct logger *l = &logger;

    l->level = MAX(LOG_EMERG, MIN(level, LOG_PVERB));
    loga("set log level to %d", l->level);
}