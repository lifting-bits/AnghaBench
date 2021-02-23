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
typedef  int /*<<< orphan*/  xml_node_t ;
struct hs20_osu_client {int /*<<< orphan*/  xml; } ;

/* Variables and functions */
 int /*<<< orphan*/ * get_node (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 char* os_strdup (char*) ; 
 char* xml_node_get_text (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xml_node_get_text_free (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static char * oma_dm_get_target_locuri(struct hs20_osu_client *ctx,
				       xml_node_t *node)
{
	xml_node_t *locuri;
	char *uri, *ret = NULL;

	locuri = get_node(ctx->xml, node, "Item/Target/LocURI");
	if (locuri == NULL)
		return NULL;

	uri = xml_node_get_text(ctx->xml, locuri);
	if (uri)
		ret = os_strdup(uri);
	xml_node_get_text_free(ctx->xml, uri);
	return ret;
}