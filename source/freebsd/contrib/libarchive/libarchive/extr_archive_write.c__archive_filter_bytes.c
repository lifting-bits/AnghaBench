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
struct archive_write_filter {int bytes_written; } ;
struct archive {int dummy; } ;
typedef  int int64_t ;

/* Variables and functions */
 struct archive_write_filter* filter_lookup (struct archive*,int) ; 

__attribute__((used)) static int64_t
_archive_filter_bytes(struct archive *_a, int n)
{
	struct archive_write_filter *f = filter_lookup(_a, n);
	return f == NULL ? -1 : f->bytes_written;
}