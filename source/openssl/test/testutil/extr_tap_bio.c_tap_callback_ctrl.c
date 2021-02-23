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
typedef  int /*<<< orphan*/  BIO_info_cb ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 long BIO_callback_ctrl (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIO_next (int /*<<< orphan*/ *) ; 

__attribute__((used)) static long tap_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp)
{
    return BIO_callback_ctrl(BIO_next(b), cmd, fp);
}