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
struct line_log_data {struct line_log_data* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct line_log_data*) ; 
 int /*<<< orphan*/  line_log_data_clear (struct line_log_data*) ; 

__attribute__((used)) static void free_line_log_data(struct line_log_data *r)
{
	while (r) {
		struct line_log_data *next = r->next;
		line_log_data_clear(r);
		free(r);
		r = next;
	}
}