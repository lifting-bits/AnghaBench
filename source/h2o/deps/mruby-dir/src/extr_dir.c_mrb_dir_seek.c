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
struct mrb_dir {int /*<<< orphan*/  dir; } ;
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;
typedef  scalar_t__ mrb_int ;

/* Variables and functions */
 int /*<<< orphan*/  E_IO_ERROR ; 
 int /*<<< orphan*/  E_NOTIMP_ERROR ; 
 int /*<<< orphan*/  mrb_dir_type ; 
 int /*<<< orphan*/  mrb_get_args (int /*<<< orphan*/ *,char*,scalar_t__*) ; 
 scalar_t__ mrb_get_datatype (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_nil_value () ; 
 int /*<<< orphan*/  mrb_raise (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  seekdir (int /*<<< orphan*/ ,long) ; 

mrb_value
mrb_dir_seek(mrb_state *mrb, mrb_value self)
{
  #if defined(_WIN32) || defined(_WIN64) || defined(__android__)
  mrb_raise(mrb, E_NOTIMP_ERROR, "dirseek() unreliable on Win platforms");
  return self;
  #else
  struct mrb_dir *mdir;
  mrb_int pos;

  mdir = (struct mrb_dir *)mrb_get_datatype(mrb, self, &mrb_dir_type);
  if (!mdir) return mrb_nil_value();
  if (!mdir->dir) {
    mrb_raise(mrb, E_IO_ERROR, "closed directory");
  }
  mrb_get_args(mrb, "i", &pos);
  seekdir(mdir->dir, (long)pos);
  return self;
  #endif
}