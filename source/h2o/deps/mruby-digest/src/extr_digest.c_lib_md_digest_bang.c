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
struct TYPE_3__ {int /*<<< orphan*/  digest_length; } ;
struct mrb_md {TYPE_1__ ctx; } ;
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;

/* Variables and functions */
 int PICOHASH_MAX_DIGEST_LENGTH ; 
 int /*<<< orphan*/  mrb_str_new (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  picohash_final (TYPE_1__*,unsigned char*) ; 
 int /*<<< orphan*/  picohash_reset (TYPE_1__*) ; 

__attribute__((used)) static mrb_value
lib_md_digest_bang(mrb_state *mrb, struct mrb_md *md)
{
  unsigned char mdstr[PICOHASH_MAX_DIGEST_LENGTH];

  picohash_final(&md->ctx, mdstr);
  picohash_reset(&md->ctx);
  return mrb_str_new(mrb, (char *)mdstr, md->ctx.digest_length);
}