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
struct file {struct cx18_open_id* private_data; } ;
struct cx18_stream {scalar_t__ type; int /*<<< orphan*/  name; struct cx18* cx; } ;
struct cx18_open_id {scalar_t__ type; scalar_t__ open_id; int /*<<< orphan*/  prio; struct cx18* cx; } ;
struct cx18 {int /*<<< orphan*/  i_flags; int /*<<< orphan*/  ana_capturing; int /*<<< orphan*/  open_id; int /*<<< orphan*/  prio; } ;

/* Variables and functions */
 int /*<<< orphan*/  CX18_DEBUG_FILE (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CX18_DEBUG_WARN (char*) ; 
 scalar_t__ CX18_ENC_STREAM_TYPE_RAD ; 
 int /*<<< orphan*/  CX18_F_I_RADIO_USER ; 
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cx18_audio_set_io (struct cx18*) ; 
 int /*<<< orphan*/  cx18_call_all (struct cx18*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ cx18_claim_stream (struct cx18_open_id*,scalar_t__) ; 
 int /*<<< orphan*/  cx18_mute (struct cx18*) ; 
 int /*<<< orphan*/  cx18_release_stream (struct cx18_stream*) ; 
 int /*<<< orphan*/  cx18_unmute (struct cx18*) ; 
 int /*<<< orphan*/  kfree (struct cx18_open_id*) ; 
 struct cx18_open_id* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s_radio ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tuner ; 
 int /*<<< orphan*/  v4l2_prio_open (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int cx18_serialized_open(struct cx18_stream *s, struct file *filp)
{
	struct cx18 *cx = s->cx;
	struct cx18_open_id *item;

	CX18_DEBUG_FILE("open %s\n", s->name);

	/* Allocate memory */
	item = kmalloc(sizeof(struct cx18_open_id), GFP_KERNEL);
	if (NULL == item) {
		CX18_DEBUG_WARN("nomem on v4l2 open\n");
		return -ENOMEM;
	}
	item->cx = cx;
	item->type = s->type;
	v4l2_prio_open(&cx->prio, &item->prio);

	item->open_id = cx->open_id++;
	filp->private_data = item;

	if (item->type == CX18_ENC_STREAM_TYPE_RAD) {
		/* Try to claim this stream */
		if (cx18_claim_stream(item, item->type)) {
			/* No, it's already in use */
			kfree(item);
			return -EBUSY;
		}

		if (!test_bit(CX18_F_I_RADIO_USER, &cx->i_flags)) {
			if (atomic_read(&cx->ana_capturing) > 0) {
				/* switching to radio while capture is
				   in progress is not polite */
				cx18_release_stream(s);
				kfree(item);
				return -EBUSY;
			}
		}

		/* Mark that the radio is being used. */
		set_bit(CX18_F_I_RADIO_USER, &cx->i_flags);
		/* We have the radio */
		cx18_mute(cx);
		/* Switch tuner to radio */
		cx18_call_all(cx, tuner, s_radio);
		/* Select the correct audio input (i.e. radio tuner) */
		cx18_audio_set_io(cx);
		/* Done! Unmute and continue. */
		cx18_unmute(cx);
	}
	return 0;
}