#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  qtail; int /*<<< orphan*/  qhead; } ;
struct ks_wlan_private {TYPE_1__ tx_dev; } ;

/* Variables and functions */
 scalar_t__ CIRC_SPACE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TX_DEVICE_BUFF_SIZE ; 

__attribute__((used)) static inline bool txq_has_space(struct ks_wlan_private *priv)
{
	return (CIRC_SPACE(priv->tx_dev.qhead, priv->tx_dev.qtail,
			   TX_DEVICE_BUFF_SIZE) > 0);
}