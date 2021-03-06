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
typedef  int /*<<< orphan*/  adns_state ;

/* Variables and functions */
 int /*<<< orphan*/  configparseerr (int /*<<< orphan*/ ,char const*,int,char*) ; 
 int /*<<< orphan*/  readconfig (int /*<<< orphan*/ ,char const*,int) ; 

__attribute__((used)) static void ccf_include(adns_state ads, const char *fn, int lno, const char *buf) {
  if (!*buf) {
    configparseerr(ads,fn,lno,"`include' directive with no filename");
    return;
  }
  readconfig(ads,buf,1);
}