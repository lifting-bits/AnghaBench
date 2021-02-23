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

/* Variables and functions */
 int /*<<< orphan*/  AMF_DATA_TYPE_STRING ; 
 int /*<<< orphan*/  bytestream_put_be16 (int /*<<< orphan*/ **,int) ; 
 int /*<<< orphan*/  bytestream_put_buffer (int /*<<< orphan*/ **,char const*,int) ; 
 int /*<<< orphan*/  bytestream_put_byte (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int strlen (char const*) ; 

void ff_amf_write_string2(uint8_t **dst, const char *str1, const char *str2)
{
    int len1 = 0, len2 = 0;
    if (str1)
        len1 = strlen(str1);
    if (str2)
        len2 = strlen(str2);
    bytestream_put_byte(dst, AMF_DATA_TYPE_STRING);
    bytestream_put_be16(dst, len1 + len2);
    bytestream_put_buffer(dst, str1, len1);
    bytestream_put_buffer(dst, str2, len2);
}