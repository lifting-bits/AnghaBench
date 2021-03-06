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
struct napi_struct {int dummy; } ;
struct iavf_q_vector {struct napi_struct napi; } ;
struct iavf_adapter {int num_msix_vectors; struct iavf_q_vector* q_vectors; } ;

/* Variables and functions */
 int NONQ_VECS ; 
 int /*<<< orphan*/  napi_enable (struct napi_struct*) ; 

__attribute__((used)) static void iavf_napi_enable_all(struct iavf_adapter *adapter)
{
	int q_idx;
	struct iavf_q_vector *q_vector;
	int q_vectors = adapter->num_msix_vectors - NONQ_VECS;

	for (q_idx = 0; q_idx < q_vectors; q_idx++) {
		struct napi_struct *napi;

		q_vector = &adapter->q_vectors[q_idx];
		napi = &q_vector->napi;
		napi_enable(napi);
	}
}