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
typedef  scalar_t__ u64 ;
typedef  int /*<<< orphan*/  sqlite3_int64 ;

/* Variables and functions */
 void* sqlite3_malloc64 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *fts5ParseAlloc(u64 t){ return sqlite3_malloc64((sqlite3_int64)t);}