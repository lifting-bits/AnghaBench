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
typedef  int /*<<< orphan*/  br_sslrec_out_clear_context ;

/* Variables and functions */
 int /*<<< orphan*/  br_enc16be (unsigned char*,size_t) ; 

__attribute__((used)) static unsigned char *
clear_encrypt(br_sslrec_out_clear_context *cc,
	int record_type, unsigned version, void *data, size_t *data_len)
{
	unsigned char *buf;

	(void)cc;
	buf = (unsigned char *)data - 5;
	buf[0] = record_type;
	br_enc16be(buf + 1, version);
	br_enc16be(buf + 3, *data_len);
	*data_len += 5;
	return buf;
}