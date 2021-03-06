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
typedef  int apr_size_t ;

/* Variables and functions */

apr_size_t
svn_cstring__reverse_match_length(const char *a,
                                  const char *b,
                                  apr_size_t max_len)
{
  apr_size_t pos = 0;

#if SVN_UNALIGNED_ACCESS_IS_OK

  /* Chunky processing is so much faster ...
   *
   * We can't make this work on architectures that require aligned access
   * because A and B will probably have different alignment. So, skipping
   * the first few chars until alignment is reached is not an option.
   */
  for (pos = sizeof(apr_size_t); pos <= max_len; pos += sizeof(apr_size_t))
    if (*(const apr_size_t*)(a - pos) != *(const apr_size_t*)(b - pos))
      break;

  pos -= sizeof(apr_size_t);

#endif

  /* If we find a mismatch at -pos, pos-1 characters matched.
   */
  while (++pos <= max_len)
    if (a[0-pos] != b[0-pos])
      return pos - 1;

  /* No mismatch found -> at least MAX_LEN matching chars.
   */
  return max_len;
}