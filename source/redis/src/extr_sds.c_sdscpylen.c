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
typedef  char* sds ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 char* sdsMakeRoomFor (char*,scalar_t__) ; 
 size_t sdsalloc (char*) ; 
 scalar_t__ sdslen (char*) ; 
 int /*<<< orphan*/  sdssetlen (char*,size_t) ; 

sds sdscpylen(sds s, const char *t, size_t len) {
    if (sdsalloc(s) < len) {
        s = sdsMakeRoomFor(s,len-sdslen(s));
        if (s == NULL) return NULL;
    }
    memcpy(s, t, len);
    s[len] = '\0';
    sdssetlen(s, len);
    return s;
}