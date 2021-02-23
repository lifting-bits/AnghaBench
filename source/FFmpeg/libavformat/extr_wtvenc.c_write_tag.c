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
typedef  int /*<<< orphan*/  AVIOContext ;

/* Variables and functions */
 int /*<<< orphan*/  avio_put_str16le (int /*<<< orphan*/ *,char const*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  write_metadata_header (int /*<<< orphan*/ *,int,char const*,int) ; 

__attribute__((used)) static void write_tag(AVIOContext *pb, const char *key, const char *value)
{
    write_metadata_header(pb, 1, key, strlen(value)*2 + 2);
    avio_put_str16le(pb, value);
}