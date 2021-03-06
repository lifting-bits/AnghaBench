#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/ * jstring ;
struct TYPE_4__ {int /*<<< orphan*/ * (* NewStringUTF ) (TYPE_1__**,char const*) ;} ;
typedef  TYPE_1__* JNIEnv ;

/* Variables and functions */
 int /*<<< orphan*/  CHECK_EXCEPTION () ; 
 int /*<<< orphan*/ * stub1 (TYPE_1__**,char const*) ; 

__attribute__((used)) static inline jstring jni_new_string(JNIEnv *env, const char *psz_string)
{
    jstring jstring = (*env)->NewStringUTF(env, psz_string);
    return !CHECK_EXCEPTION() ? jstring : NULL;
}