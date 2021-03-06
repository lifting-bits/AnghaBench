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
struct wlan_network {int /*<<< orphan*/  list; scalar_t__ fixed; } ;
struct __queue {int /*<<< orphan*/  queue; } ;
struct mlme_priv {int /*<<< orphan*/  num_of_scanned; struct __queue free_bss_pool; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void free_network_nolock(struct mlme_priv *pmlmepriv,
			  struct wlan_network *pnetwork)
{
	struct  __queue *free_queue = &pmlmepriv->free_bss_pool;

	if (!pnetwork)
		return;
	if (pnetwork->fixed)
		return;
	list_del_init(&pnetwork->list);
	list_add_tail(&pnetwork->list, &free_queue->queue);
	pmlmepriv->num_of_scanned--;
}