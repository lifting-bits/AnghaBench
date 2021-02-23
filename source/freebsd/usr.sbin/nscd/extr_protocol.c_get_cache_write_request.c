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
struct cache_write_request {int dummy; } ;
struct comm_element {scalar_t__ type; struct cache_write_request c_write_request; } ;

/* Variables and functions */
 scalar_t__ CET_WRITE_REQUEST ; 
 int /*<<< orphan*/  TRACE_IN (struct cache_write_request* (*) (struct comm_element*)) ; 
 int /*<<< orphan*/  TRACE_OUT (struct cache_write_request* (*) (struct comm_element*)) ; 
 int /*<<< orphan*/  assert (int) ; 

struct cache_write_request *
get_cache_write_request(struct comm_element *element)
{

	TRACE_IN(get_cache_write_request);
	assert(element->type == CET_WRITE_REQUEST);
	TRACE_OUT(get_cache_write_request);
	return (&element->c_write_request);
}