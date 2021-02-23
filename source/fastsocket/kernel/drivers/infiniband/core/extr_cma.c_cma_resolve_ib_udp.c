#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct ib_cm_id* ib; } ;
struct TYPE_4__ {int /*<<< orphan*/  path_rec; } ;
struct TYPE_6__ {TYPE_1__ route; int /*<<< orphan*/  device; } ;
struct rdma_id_private {TYPE_2__ cm_id; TYPE_3__ id; } ;
struct rdma_conn_param {scalar_t__ private_data_len; int /*<<< orphan*/  private_data; } ;
struct ib_cm_sidr_req_param {scalar_t__ private_data_len; int timeout_ms; int /*<<< orphan*/ * private_data; int /*<<< orphan*/  max_cm_retries; int /*<<< orphan*/  service_id; int /*<<< orphan*/  path; } ;
struct ib_cm_id {int dummy; } ;

/* Variables and functions */
 int CMA_CM_RESPONSE_TIMEOUT ; 
 int /*<<< orphan*/  CMA_MAX_CM_RETRIES ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 scalar_t__ IS_ERR (struct ib_cm_id*) ; 
 int PTR_ERR (struct ib_cm_id*) ; 
 int /*<<< orphan*/  cma_dst_addr (struct rdma_id_private*) ; 
 int cma_format_hdr (void*,struct rdma_id_private*) ; 
 int /*<<< orphan*/  cma_sidr_rep_handler ; 
 int cma_user_data_offset (struct rdma_id_private*) ; 
 struct ib_cm_id* ib_create_cm_id (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct rdma_id_private*) ; 
 int /*<<< orphan*/  ib_destroy_cm_id (struct ib_cm_id*) ; 
 int ib_send_cm_sidr_req (struct ib_cm_id*,struct ib_cm_sidr_req_param*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kzalloc (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  rdma_get_service_id (TYPE_3__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int cma_resolve_ib_udp(struct rdma_id_private *id_priv,
			      struct rdma_conn_param *conn_param)
{
	struct ib_cm_sidr_req_param req;
	struct ib_cm_id	*id;
	int offset, ret;

	offset = cma_user_data_offset(id_priv);
	req.private_data_len = offset + conn_param->private_data_len;
	if (req.private_data_len < conn_param->private_data_len)
		return -EINVAL;

	if (req.private_data_len) {
		req.private_data = kzalloc(req.private_data_len, GFP_ATOMIC);
		if (!req.private_data)
			return -ENOMEM;
	} else {
		req.private_data = NULL;
	}

	if (conn_param->private_data && conn_param->private_data_len)
		memcpy((void *) req.private_data + offset,
		       conn_param->private_data, conn_param->private_data_len);

	if (req.private_data) {
		ret = cma_format_hdr((void *) req.private_data, id_priv);
		if (ret)
			goto out;
	}

	id = ib_create_cm_id(id_priv->id.device, cma_sidr_rep_handler,
			     id_priv);
	if (IS_ERR(id)) {
		ret = PTR_ERR(id);
		goto out;
	}
	id_priv->cm_id.ib = id;

	req.path = id_priv->id.route.path_rec;
	req.service_id = rdma_get_service_id(&id_priv->id, cma_dst_addr(id_priv));
	req.timeout_ms = 1 << (CMA_CM_RESPONSE_TIMEOUT - 8);
	req.max_cm_retries = CMA_MAX_CM_RETRIES;

	ret = ib_send_cm_sidr_req(id_priv->cm_id.ib, &req);
	if (ret) {
		ib_destroy_cm_id(id_priv->cm_id.ib);
		id_priv->cm_id.ib = NULL;
	}
out:
	kfree(req.private_data);
	return ret;
}