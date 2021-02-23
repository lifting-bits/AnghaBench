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
struct lev_targ_click_ext {int price; int user_id; } ;
struct advert {int flags; int price; } ;

/* Variables and functions */
 int ADF_ANCIENT ; 
 int /*<<< orphan*/  LEV_TARG_CLICK ; 
 int /*<<< orphan*/  LEV_TARG_CLICK_EXT ; 
 scalar_t__ ad_became_ancient (struct advert*) ; 
 struct lev_targ_click_ext* alloc_log_event (int /*<<< orphan*/ ,int,int) ; 
 int conv_user_id (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,...) ; 
 struct advert* get_ad_f (int,int /*<<< orphan*/ ) ; 
 int register_user_click (struct lev_targ_click_ext*) ; 
 int /*<<< orphan*/  stderr ; 
 int verbosity ; 

int do_register_user_click (int user_id, int ad_id, int price) {
  struct advert *A = get_ad_f (ad_id, 0);
  struct lev_targ_click_ext *E;
  int uid = conv_user_id (user_id);
  if (verbosity > 1) {
    fprintf (stderr, "user %d clicks on ad %d, price %d\n", user_id, ad_id, price);
  }
  if (uid < 0) {
    if (verbosity > 0) {
      fprintf (stderr, "error: unknown user %d, click neglected\n", user_id);
    }
    return -1;
  }
  if (!A || (A->flags & ADF_ANCIENT) || ad_became_ancient (A) || (A->price > 0 && price < 0)) {
    if (verbosity > 0) {
      fprintf (stderr, "warning: user %d clicks on ad %d, price %d; known ad price is %d, click ignored\n", 
	user_id, ad_id, price, A ? A->price : -1);
    }
    return -1;
  }
  if (A->price == price || (A->price < 0 && price < 0)) {
    E = alloc_log_event (LEV_TARG_CLICK, 12, ad_id);
  } else {
    E = alloc_log_event (LEV_TARG_CLICK_EXT, 16, ad_id);
    E->price = price;
  }
  E->user_id = user_id;

  return register_user_click (E);
}