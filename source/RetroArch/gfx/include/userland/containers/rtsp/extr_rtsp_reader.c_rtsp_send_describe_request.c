#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_2__* priv; } ;
typedef  TYPE_3__ VC_CONTAINER_T ;
typedef  int /*<<< orphan*/  VC_CONTAINER_STATUS_T ;
struct TYPE_11__ {char* comms_buffer; int /*<<< orphan*/  cseq_value; } ;
typedef  TYPE_4__ VC_CONTAINER_MODULE_T ;
struct TYPE_9__ {TYPE_1__* io; TYPE_4__* module; } ;
struct TYPE_8__ {char* uri; } ;

/* Variables and functions */
 int COMMS_BUFFER_SIZE ; 
 int /*<<< orphan*/  DESCRIBE_METHOD ; 
 int /*<<< orphan*/  LOG_ERROR (TYPE_3__*,char*,scalar_t__,scalar_t__) ; 
 char* RTSP_REQUEST_LINE_FORMAT ; 
 scalar_t__ RTSP_URI_LENGTH_MAX ; 
 char* TRAILING_HEADERS_FORMAT ; 
 int /*<<< orphan*/  VC_CONTAINER_ERROR_URI_OPEN_FAILED ; 
 int /*<<< orphan*/  rtsp_send (TYPE_3__*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int /*<<< orphan*/ ,...) ; 
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  vc_container_assert (int) ; 

__attribute__((used)) static VC_CONTAINER_STATUS_T rtsp_send_describe_request( VC_CONTAINER_T *p_ctx )
{
   VC_CONTAINER_MODULE_T *module = p_ctx->priv->module;
   char *ptr = module->comms_buffer, *end = ptr + COMMS_BUFFER_SIZE;
   char *uri = p_ctx->priv->io->uri;

   if (strlen(uri) > RTSP_URI_LENGTH_MAX)
   {
      LOG_ERROR(p_ctx, "RTSP: URI is too long (%d>%d)", strlen(uri), RTSP_URI_LENGTH_MAX);
      return VC_CONTAINER_ERROR_URI_OPEN_FAILED;
   }

   ptr += snprintf(ptr, end - ptr, RTSP_REQUEST_LINE_FORMAT, DESCRIBE_METHOD, uri);
   if (ptr < end)
      ptr += snprintf(ptr, end - ptr, TRAILING_HEADERS_FORMAT, module->cseq_value++);
   vc_container_assert(ptr < end);

   return rtsp_send(p_ctx);
}