#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct sk_buff {int data; int len; } ;
struct ieee80211_rx_status {int flag; } ;
struct ieee80211_rx_data {int security_idx; struct sk_buff* skb; int /*<<< orphan*/  sta; struct ieee80211_key* key; } ;
struct TYPE_3__ {int /*<<< orphan*/ * rx_pn; int /*<<< orphan*/  tfm; int /*<<< orphan*/  replays; } ;
struct TYPE_4__ {TYPE_1__ ccmp; } ;
struct ieee80211_key {TYPE_2__ u; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
typedef  int /*<<< orphan*/  ieee80211_rx_result ;

/* Variables and functions */
 int AES_BLOCK_SIZE ; 
 int CCMP_HDR_LEN ; 
 int CCMP_MIC_LEN ; 
 int CCMP_PN_LEN ; 
 struct ieee80211_rx_status* IEEE80211_SKB_RXCB (struct sk_buff*) ; 
 int /*<<< orphan*/  RX_CONTINUE ; 
 int /*<<< orphan*/  RX_DROP_UNUSABLE ; 
 int RX_FLAG_DECRYPTED ; 
 int /*<<< orphan*/  ccmp_hdr2pn (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ccmp_special_blocks (struct sk_buff*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ ieee80211_aes_ccm_decrypt (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,int,int) ; 
 int ieee80211_hdrlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_is_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_is_robust_mgmt_frame (struct ieee80211_hdr*) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memmove (int,int,int) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 scalar_t__ pskb_trim (struct sk_buff*,int) ; 
 scalar_t__ skb_linearize (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 

ieee80211_rx_result
ieee80211_crypto_ccmp_decrypt(struct ieee80211_rx_data *rx)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)rx->skb->data;
	int hdrlen;
	struct ieee80211_key *key = rx->key;
	struct sk_buff *skb = rx->skb;
	struct ieee80211_rx_status *status = IEEE80211_SKB_RXCB(skb);
	u8 pn[CCMP_PN_LEN];
	int data_len;
	int queue;

	hdrlen = ieee80211_hdrlen(hdr->frame_control);

	if (!ieee80211_is_data(hdr->frame_control) &&
	    !ieee80211_is_robust_mgmt_frame(hdr))
		return RX_CONTINUE;

	data_len = skb->len - hdrlen - CCMP_HDR_LEN - CCMP_MIC_LEN;
	if (!rx->sta || data_len < 0)
		return RX_DROP_UNUSABLE;

	if (status->flag & RX_FLAG_DECRYPTED) {
		if (!pskb_may_pull(rx->skb, hdrlen + CCMP_HDR_LEN))
			return RX_DROP_UNUSABLE;
	} else {
		if (skb_linearize(rx->skb))
			return RX_DROP_UNUSABLE;
	}

	ccmp_hdr2pn(pn, skb->data + hdrlen);

	queue = rx->security_idx;

	if (memcmp(pn, key->u.ccmp.rx_pn[queue], CCMP_PN_LEN) <= 0) {
		key->u.ccmp.replays++;
		return RX_DROP_UNUSABLE;
	}

	if (!(status->flag & RX_FLAG_DECRYPTED)) {
		u8 scratch[6 * AES_BLOCK_SIZE];
		/* hardware didn't decrypt/verify MIC */
		ccmp_special_blocks(skb, pn, scratch, 1);

		if (ieee80211_aes_ccm_decrypt(
			    key->u.ccmp.tfm, scratch,
			    skb->data + hdrlen + CCMP_HDR_LEN, data_len,
			    skb->data + skb->len - CCMP_MIC_LEN,
			    skb->data + hdrlen + CCMP_HDR_LEN))
			return RX_DROP_UNUSABLE;
	}

	memcpy(key->u.ccmp.rx_pn[queue], pn, CCMP_PN_LEN);

	/* Remove CCMP header and MIC */
	if (pskb_trim(skb, skb->len - CCMP_MIC_LEN))
		return RX_DROP_UNUSABLE;
	memmove(skb->data + CCMP_HDR_LEN, skb->data, hdrlen);
	skb_pull(skb, CCMP_HDR_LEN);

	return RX_CONTINUE;
}