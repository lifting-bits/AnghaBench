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
struct my_data {int /*<<< orphan*/  read_return; int /*<<< orphan*/  read_called; int /*<<< orphan*/  magic; } ;
struct archive {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAGIC ; 
 int /*<<< orphan*/  assertEqualInt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t
my_read(struct archive *a, void *_private, const void **buff)
{
	struct my_data *private = (struct my_data *)_private;
	(void)a; /* UNUSED */
	(void)buff; /* UNUSED */
	assertEqualInt(MAGIC, private->magic);
	++private->read_called;
	return (private->read_return);
}