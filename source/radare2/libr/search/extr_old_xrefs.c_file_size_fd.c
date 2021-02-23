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
typedef  int /*<<< orphan*/  ut32 ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_CUR ; 
 int /*<<< orphan*/  SEEK_END ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  lseek (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ut32 file_size_fd(int fd)
{
	ut32 curr = lseek(fd, 0, SEEK_CUR);
	ut32 size = lseek(fd, 0, SEEK_END); // XXX: this is not size, is rest!
	lseek(fd, curr, SEEK_SET);

	return size;
}