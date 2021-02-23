#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  d_sd; int /*<<< orphan*/  c_sd; } ;

/* Variables and functions */
 int /*<<< orphan*/  ftp_close_filesystem_on_error () ; 
 TYPE_1__ ftp_data ; 
 int /*<<< orphan*/  servers_close_socket (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ftp_close_cmd_data (void) {
    servers_close_socket(&ftp_data.c_sd);
    servers_close_socket(&ftp_data.d_sd);
    ftp_close_filesystem_on_error ();
}