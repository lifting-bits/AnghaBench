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
struct bio {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bio_free (struct bio*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fs_bio_set ; 

__attribute__((used)) static void bio_fs_destructor(struct bio *bio)
{
	bio_free(bio, fs_bio_set);
}