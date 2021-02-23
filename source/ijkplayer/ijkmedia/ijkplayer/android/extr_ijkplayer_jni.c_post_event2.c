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
typedef  int /*<<< orphan*/  jobject ;
typedef  int /*<<< orphan*/  JNIEnv ;

/* Variables and functions */
 int /*<<< orphan*/  J4AC_IjkMediaPlayer__postEventFromNative (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) inline static void post_event2(JNIEnv *env, jobject weak_this, int what, int arg1, int arg2, jobject obj)
{
    // MPTRACE("post_event2(%p, %p, %d, %d, %d, %p)", (void*)env, (void*) weak_this, what, arg1, arg2, (void*)obj);
    J4AC_IjkMediaPlayer__postEventFromNative(env, weak_this, what, arg1, arg2, obj);
    // MPTRACE("post_event2()=void");
}