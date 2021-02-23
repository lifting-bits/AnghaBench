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
typedef  int /*<<< orphan*/  uint64_t ;
struct drm_property {int flags; int num_values; char* name; struct drm_property* values; int /*<<< orphan*/  head; int /*<<< orphan*/  enum_blob_list; int /*<<< orphan*/  base; } ;
struct TYPE_2__ {int /*<<< orphan*/  property_list; } ;
struct drm_device {TYPE_1__ mode_config; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_MEM_KMS ; 
 int /*<<< orphan*/  DRM_MODE_OBJECT_PROPERTY ; 
 int DRM_PROP_NAME_LEN ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int M_WAITOK ; 
 int M_ZERO ; 
 int drm_mode_object_get (struct drm_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (struct drm_property*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* malloc (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int) ; 

struct drm_property *drm_property_create(struct drm_device *dev, int flags,
					 const char *name, int num_values)
{
	struct drm_property *property = NULL;
	int ret;

	property = malloc(sizeof(struct drm_property), DRM_MEM_KMS,
	    M_WAITOK | M_ZERO);
	if (!property)
		return NULL;

	if (num_values) {
		property->values = malloc(sizeof(uint64_t)*num_values, DRM_MEM_KMS,
		    M_WAITOK | M_ZERO);
		if (!property->values)
			goto fail;
	}

	ret = drm_mode_object_get(dev, &property->base, DRM_MODE_OBJECT_PROPERTY);
	if (ret)
		goto fail;

	property->flags = flags;
	property->num_values = num_values;
	INIT_LIST_HEAD(&property->enum_blob_list);

	if (name) {
		strncpy(property->name, name, DRM_PROP_NAME_LEN);
		property->name[DRM_PROP_NAME_LEN-1] = '\0';
	}

	list_add_tail(&property->head, &dev->mode_config.property_list);
	return property;
fail:
	free(property->values, DRM_MEM_KMS);
	free(property, DRM_MEM_KMS);
	return NULL;
}