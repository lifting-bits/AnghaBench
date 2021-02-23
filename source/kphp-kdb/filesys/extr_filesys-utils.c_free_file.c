#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct TYPE_5__* filename; } ;
typedef  TYPE_1__ file_t ;

/* Variables and functions */
 int strlen (TYPE_1__*) ; 
 int /*<<< orphan*/  zfree (TYPE_1__*,int) ; 

__attribute__((used)) static void free_file (file_t *p) {
  if (p->filename) {
    zfree (p->filename, strlen (p->filename) + 1);
  }
  zfree (p, sizeof (*p));
}