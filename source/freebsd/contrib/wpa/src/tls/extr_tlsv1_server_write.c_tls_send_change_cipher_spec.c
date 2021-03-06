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
typedef  int /*<<< orphan*/  u8 ;
struct tlsv1_server {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESTABLISHED ; 
 int /*<<< orphan*/  os_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * os_malloc (int) ; 
 scalar_t__ tls_write_server_change_cipher_spec (struct tlsv1_server*,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 scalar_t__ tls_write_server_finished (struct tlsv1_server*,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tlsv1_server_log (struct tlsv1_server*,char*) ; 

__attribute__((used)) static u8 * tls_send_change_cipher_spec(struct tlsv1_server *conn,
					size_t *out_len)
{
	u8 *msg, *end, *pos;

	*out_len = 0;

	msg = os_malloc(1000);
	if (msg == NULL)
		return NULL;

	pos = msg;
	end = msg + 1000;

	if (tls_write_server_change_cipher_spec(conn, &pos, end) < 0 ||
	    tls_write_server_finished(conn, &pos, end) < 0) {
		os_free(msg);
		return NULL;
	}

	*out_len = pos - msg;

	tlsv1_server_log(conn, "Handshake completed successfully");
	conn->state = ESTABLISHED;

	return msg;
}