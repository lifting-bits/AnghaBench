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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  WiFiScanPayload ;
typedef  int /*<<< orphan*/  ProtobufCAllocator ;

/* Variables and functions */
 scalar_t__ protobuf_c_message_unpack (int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  wi_fi_scan_payload__descriptor ; 

WiFiScanPayload *
       wi_fi_scan_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (WiFiScanPayload *)
     protobuf_c_message_unpack (&wi_fi_scan_payload__descriptor,
                                allocator, len, data);
}