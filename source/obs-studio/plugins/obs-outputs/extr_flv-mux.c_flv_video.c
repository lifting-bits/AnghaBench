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
typedef  int uint32_t ;
struct serializer {int dummy; } ;
struct encoder_packet {scalar_t__ size; int /*<<< orphan*/  data; scalar_t__ keyframe; scalar_t__ dts; scalar_t__ pts; } ;
typedef  scalar_t__ int64_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_DEBUG ; 
 int RTMP_PACKET_TYPE_VIDEO ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,...) ; 
 int get_ms_time (struct encoder_packet*,scalar_t__) ; 
 int last_time ; 
 int /*<<< orphan*/  s_w8 (struct serializer*,int) ; 
 int /*<<< orphan*/  s_wb24 (struct serializer*,int) ; 
 int /*<<< orphan*/  s_wb32 (struct serializer*,int) ; 
 int /*<<< orphan*/  s_write (struct serializer*,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ serializer_get_pos (struct serializer*) ; 

__attribute__((used)) static void flv_video(struct serializer *s, int32_t dts_offset,
		      struct encoder_packet *packet, bool is_header)
{
	int64_t offset = packet->pts - packet->dts;
	int32_t time_ms = get_ms_time(packet, packet->dts) - dts_offset;

	if (!packet->data || !packet->size)
		return;

	s_w8(s, RTMP_PACKET_TYPE_VIDEO);

#ifdef DEBUG_TIMESTAMPS
	blog(LOG_DEBUG, "Video: %lu", time_ms);

	if (last_time > time_ms)
		blog(LOG_DEBUG, "Non-monotonic");

	last_time = time_ms;
#endif

	s_wb24(s, (uint32_t)packet->size + 5);
	s_wb24(s, time_ms);
	s_w8(s, (time_ms >> 24) & 0x7F);
	s_wb24(s, 0);

	/* these are the 5 extra bytes mentioned above */
	s_w8(s, packet->keyframe ? 0x17 : 0x27);
	s_w8(s, is_header ? 0 : 1);
	s_wb24(s, get_ms_time(packet, offset));
	s_write(s, packet->data, packet->size);

	/* write tag size (starting byte doesn't count) */
	s_wb32(s, (uint32_t)serializer_get_pos(s) - 1);
}