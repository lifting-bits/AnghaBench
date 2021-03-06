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
typedef  int /*<<< orphan*/  u32 ;
struct tcp_sock {int snd_cwnd; int snd_ssthresh; int bytes_acked; int mss_cache; int snd_cwnd_clamp; } ;
struct sock {int dummy; } ;

/* Variables and functions */
 scalar_t__ sysctl_tcp_abc ; 
 int /*<<< orphan*/  tcp_cong_avoid_ai (struct tcp_sock*,int) ; 
 int /*<<< orphan*/  tcp_is_cwnd_limited (struct sock*,int /*<<< orphan*/ ) ; 
 struct tcp_sock* tcp_sk (struct sock*) ; 
 int /*<<< orphan*/  tcp_slow_start (struct tcp_sock*) ; 

void tcp_reno_cong_avoid(struct sock *sk, u32 ack, u32 in_flight)
{
	struct tcp_sock *tp = tcp_sk(sk);

	if (!tcp_is_cwnd_limited(sk, in_flight))
		return;

	/* In "safe" area, increase. */
	if (tp->snd_cwnd <= tp->snd_ssthresh)
		tcp_slow_start(tp);

	/* In dangerous area, increase slowly. */
	else if (sysctl_tcp_abc) {
		/* RFC3465: Appropriate Byte Count
		 * increase once for each full cwnd acked
		 */
		if (tp->bytes_acked >= tp->snd_cwnd*tp->mss_cache) {
			tp->bytes_acked -= tp->snd_cwnd*tp->mss_cache;
			if (tp->snd_cwnd < tp->snd_cwnd_clamp)
				tp->snd_cwnd++;
		}
	} else {
		tcp_cong_avoid_ai(tp, tp->snd_cwnd);
	}
}