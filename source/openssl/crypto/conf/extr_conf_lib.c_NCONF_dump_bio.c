#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* meth; } ;
struct TYPE_5__ {int (* dump ) (TYPE_2__ const*,int /*<<< orphan*/ *) ;} ;
typedef  TYPE_2__ CONF ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  CONF_F_NCONF_DUMP_BIO ; 
 int /*<<< orphan*/  CONF_R_NO_CONF ; 
 int /*<<< orphan*/  CONFerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (TYPE_2__ const*,int /*<<< orphan*/ *) ; 

int NCONF_dump_bio(const CONF *conf, BIO *out)
{
    if (conf == NULL) {
        CONFerr(CONF_F_NCONF_DUMP_BIO, CONF_R_NO_CONF);
        return 0;
    }

    return conf->meth->dump(conf, out);
}