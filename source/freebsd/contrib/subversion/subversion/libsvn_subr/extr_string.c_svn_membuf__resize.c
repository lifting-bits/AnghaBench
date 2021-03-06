#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {void* data; int /*<<< orphan*/  pool; int /*<<< orphan*/  size; } ;
typedef  TYPE_1__ svn_membuf_t ;
typedef  int /*<<< orphan*/  apr_size_t ;

/* Variables and functions */
 int /*<<< orphan*/  membuf_ensure (void**,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void const* const,void const* const,int /*<<< orphan*/  const) ; 

void
svn_membuf__resize(svn_membuf_t *membuf, apr_size_t size)
{
  const void *const old_data = membuf->data;
  const apr_size_t old_size = membuf->size;

  membuf_ensure(&membuf->data, &membuf->size, size, membuf->pool);

  /* If we re-allocated MEMBUF->DATA, it cannot be NULL.
   * Statically initialized membuffers (OLD_DATA) may be NULL, though. */
  if (old_data && old_data != membuf->data)
    memcpy(membuf->data, old_data, old_size);
}