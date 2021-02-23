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
struct Vector {scalar_t__ capacity; scalar_t__ current; int /*<<< orphan*/  pData; } ;

/* Variables and functions */
 int /*<<< orphan*/  CoTaskMemFree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void delete_vector(struct Vector * v)
{
    CoTaskMemFree(v->pData);
    v->current = 0;
    v->capacity = 0;
}