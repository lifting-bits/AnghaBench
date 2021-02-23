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
 int find_arg (int,char**,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  test_super (char*,char*,char*) ; 
 int /*<<< orphan*/  train_super (char*,char*,int) ; 

void run_super(int argc, char **argv)
{
    if(argc < 4){
        fprintf(stderr, "usage: %s %s [train/test/valid] [cfg] [weights (optional)]\n", argv[0], argv[1]);
        return;
    }

    char *cfg = argv[3];
    char *weights = (argc > 4) ? argv[4] : 0;
    char *filename = (argc > 5) ? argv[5] : 0;
    int clear = find_arg(argc, argv, "-clear");
    if(0==strcmp(argv[2], "train")) train_super(cfg, weights, clear);
    else if(0==strcmp(argv[2], "test")) test_super(cfg, weights, filename);
    /*
    else if(0==strcmp(argv[2], "valid")) validate_super(cfg, weights);
    */
}