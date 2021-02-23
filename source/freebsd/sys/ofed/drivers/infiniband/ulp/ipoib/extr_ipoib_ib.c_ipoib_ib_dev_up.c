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
struct ipoib_dev_priv {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPOIB_FLAG_OPER_UP ; 
 int /*<<< orphan*/  IPOIB_PKEY_ASSIGNED ; 
 int /*<<< orphan*/  ipoib_dbg (struct ipoib_dev_priv*,char*) ; 
 int ipoib_mcast_start_thread (struct ipoib_dev_priv*) ; 
 int /*<<< orphan*/  ipoib_pkey_dev_check_presence (struct ipoib_dev_priv*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int ipoib_ib_dev_up(struct ipoib_dev_priv *priv)
{

	ipoib_pkey_dev_check_presence(priv);

	if (!test_bit(IPOIB_PKEY_ASSIGNED, &priv->flags)) {
		ipoib_dbg(priv, "PKEY is not assigned.\n");
		return 0;
	}

	set_bit(IPOIB_FLAG_OPER_UP, &priv->flags);

	return ipoib_mcast_start_thread(priv);
}