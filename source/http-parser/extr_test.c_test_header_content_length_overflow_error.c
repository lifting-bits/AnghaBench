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
typedef  int /*<<< orphan*/  c ;
typedef  int /*<<< orphan*/  b ;
typedef  int /*<<< orphan*/  a ;

/* Variables and functions */
 char* X (int) ; 
 int /*<<< orphan*/  test_content_length_overflow (char const*,int,int) ; 

void
test_header_content_length_overflow_error (void)
{
#define X(size)                                                               \
  "HTTP/1.1 200 OK\r\n"                                                       \
  "Content-Length: " #size "\r\n"                                             \
  "\r\n"
  const char a[] = X(1844674407370955160);  /* 2^64 / 10 - 1 */
  const char b[] = X(18446744073709551615); /* 2^64-1 */
  const char c[] = X(18446744073709551616); /* 2^64   */
#undef X
  test_content_length_overflow(a, sizeof(a) - 1, 1); /* expect ok      */
  test_content_length_overflow(b, sizeof(b) - 1, 0); /* expect failure */
  test_content_length_overflow(c, sizeof(c) - 1, 0); /* expect failure */
}