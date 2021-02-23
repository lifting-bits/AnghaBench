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

/* Variables and functions */
 scalar_t__ MAX_FN ; 
 scalar_t__ ansI ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ atoi (void*) ; 
 scalar_t__ change_user (char*) ; 
 int /*<<< orphan*/  dl_open_file (scalar_t__,void*,int) ; 
 int /*<<< orphan*/  dl_set_debug_handlers () ; 
 void* dump_name ; 
 scalar_t__ engineF ; 
 scalar_t__ engineN ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  flush_w_buff () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  init_data () ; 
 void* optarg ; 
 int optind ; 
 void* out_name ; 
 char* progname ; 
 int /*<<< orphan*/  run () ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  usage () ; 
 char* username ; 

int main (int argc, char *argv[]) {
  int i;

  dl_set_debug_handlers ();
  progname = argv[0];

  if (argc == 1) {
    usage();
    return 2;
  }

  while ((i = getopt (argc, argv, "d:hF:N:o:u:")) != -1) {
    switch (i) {
    case 'd':
      dump_name = optarg;
      break;
    case 'h':
      usage ();
      return 2;
    case 'F':
      engineF = atoi (optarg);
      break;
    case 'N':
      engineN = atoi (optarg);
      break;
    case 'o':
      out_name = optarg;
      break;
    case 'u':
      username = optarg;
      break;
    }
  }

  if (argc != optind) {
    usage();
    return 2;
  }

  if (change_user (username) < 0) {
    fprintf (stderr, "fatal: cannot change user to %s\n", username ? username : "(none)");
    exit (1);
  }

  assert (engineN > engineF && engineF >= 0);
  ansI = engineN + 1;

  assert (engineN + 1 < MAX_FN);

  dl_open_file (ansI, out_name, 2);

  init_data();
  run();

  flush_w_buff();
  return 0;
}