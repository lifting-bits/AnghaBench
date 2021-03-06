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
struct sshkey {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  default_key_sign ; 
 int sshkey_certify_custom (struct sshkey*,struct sshkey*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
sshkey_certify(struct sshkey *k, struct sshkey *ca, const char *alg)
{
	return sshkey_certify_custom(k, ca, alg, default_key_sign, NULL);
}