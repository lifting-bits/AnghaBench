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
typedef  int /*<<< orphan*/  u16 ;
struct wpabuf {int dummy; } ;
struct teap_tlv_hdr {void* length; void* tlv_type; } ;
typedef  int /*<<< orphan*/  hdr ;

/* Variables and functions */
 void* host_to_be16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wpabuf_put_data (struct wpabuf*,struct teap_tlv_hdr*,int) ; 

void eap_teap_put_tlv_hdr(struct wpabuf *buf, u16 type, u16 len)
{
	struct teap_tlv_hdr hdr;

	hdr.tlv_type = host_to_be16(type);
	hdr.length = host_to_be16(len);
	wpabuf_put_data(buf, &hdr, sizeof(hdr));
}