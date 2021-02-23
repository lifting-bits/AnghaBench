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
typedef  int /*<<< orphan*/  sldns_buffer ;

/* Variables and functions */
 int /*<<< orphan*/  sldns_buffer_begin (int /*<<< orphan*/ *) ; 
 size_t sldns_buffer_capacity (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sldns_buffer_clear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sldns_buffer_flip (int /*<<< orphan*/ *) ; 
 size_t sldns_buffer_limit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sldns_buffer_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 

void 
sldns_buffer_copy(sldns_buffer* result, sldns_buffer* from)
{
	size_t tocopy = sldns_buffer_limit(from);

	if(tocopy > sldns_buffer_capacity(result))
		tocopy = sldns_buffer_capacity(result);
	sldns_buffer_clear(result);
	sldns_buffer_write(result, sldns_buffer_begin(from), tocopy);
	sldns_buffer_flip(result);
}