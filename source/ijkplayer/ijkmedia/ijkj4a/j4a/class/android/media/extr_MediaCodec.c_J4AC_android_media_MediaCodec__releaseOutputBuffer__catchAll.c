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
typedef  int /*<<< orphan*/  jint ;
typedef  int /*<<< orphan*/  jboolean ;
typedef  int /*<<< orphan*/  JNIEnv ;

/* Variables and functions */
 int /*<<< orphan*/  J4AC_android_media_MediaCodec__releaseOutputBuffer (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  J4A_ExceptionCheck__catchAll (int /*<<< orphan*/ *) ; 

void J4AC_android_media_MediaCodec__releaseOutputBuffer__catchAll(JNIEnv *env, jobject thiz, jint index, jboolean render)
{
    J4AC_android_media_MediaCodec__releaseOutputBuffer(env, thiz, index, render);
    J4A_ExceptionCheck__catchAll(env);
}