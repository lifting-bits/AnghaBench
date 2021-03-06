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
struct amdtp_stream {int /*<<< orphan*/  data_block_quadlets; struct amdtp_ff* protocol; } ;
struct amdtp_ff {unsigned int pcm_channels; } ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le32 (int) ; 

__attribute__((used)) static void write_pcm_silence(struct amdtp_stream *s,
			      __le32 *buffer, unsigned int frames)
{
	struct amdtp_ff *p = s->protocol;
	unsigned int i, c, channels = p->pcm_channels;

	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c)
			buffer[c] = cpu_to_le32(0x00000000);
		buffer += s->data_block_quadlets;
	}
}