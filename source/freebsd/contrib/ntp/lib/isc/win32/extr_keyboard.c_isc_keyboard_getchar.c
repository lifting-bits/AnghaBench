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
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  isc_result_t ;
struct TYPE_3__ {int /*<<< orphan*/  result; int /*<<< orphan*/  fd; } ;
typedef  TYPE_1__ isc_keyboard_t ;

/* Variables and functions */
 int /*<<< orphan*/  ISC_R_IOERROR ; 
 int /*<<< orphan*/  ISC_R_SUCCESS ; 
 int /*<<< orphan*/  REQUIRE (int /*<<< orphan*/ ) ; 
 scalar_t__ read (int /*<<< orphan*/ ,unsigned char*,int) ; 

isc_result_t
isc_keyboard_getchar(isc_keyboard_t *keyboard, unsigned char *cp) {
	ssize_t cc;
	unsigned char c;

	REQUIRE(keyboard != NULL);
	REQUIRE(cp != NULL);

	cc = read(keyboard->fd, &c, 1);
	if (cc < 0) {
		keyboard->result = ISC_R_IOERROR;
		return (keyboard->result);
	}

	*cp = c;

	return (ISC_R_SUCCESS);
}